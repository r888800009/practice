from pwn import *
import angr
import claripy

# smallest AEG

elf = ELF('./taint-angr')

p = angr.Project('./taint-angr')
state = p.factory.entry_state()

# 為了找到 exploitable 必須啟用 `save_unconstrained=True`
"""
這裡 angr 似乎幫你 hook 了
#p.hook_symbol('strncmp', angr.SIM_PROCEDURES['libc']['strncmp']()) # 如果自己 hook 部分東西似乎會有問題?這個會導致 angr 爛掉
p.hook_symbol('puts', angr.SIM_PROCEDURES['libc']['puts']())
p.hook_symbol('__libc_start_main', angr.SIM_PROCEDURES['glibc']['__libc_start_main']())
#p.hook_symbol('__stack_chk_fail', angr.SIM_PROCEDURES['libc']['__stack_chk_fail']())
p.hook_symbol('strncpy', angr.SIM_PROCEDURES['libc']['strncpy']())
p.hook_symbol('strlen', angr.SIM_PROCEDURES['libc']['strlen']())
p.hook_symbol('memcpy', angr.SIM_PROCEDURES['libc']['memcpy']())
p.hook_symbol('gets', angr.SIM_PROCEDURES['libc']['gets']())
"""

bvs1 = claripy.BVS('source_1', 8 * 20)
state.memory.store(elf.symbols['source'], bvs1)

sm = p.factory.simulation_manager(state, save_unconstrained=True)
sm.run()

print((sm))
print(len(sm.active))

u1 = sm.deadended[-1]
for u in sm.deadended:
    #u.solver.add(u.memory.load(elf.symbols['source']+20, 8) == ord('C'))
    #u.add_constraints(u.mem[elf.symbols['sink']+12].char == ord('C'))
    #u.add_constraints(u.memory.load(elf.symbols['sink']+20, 8).symbolic)
    if u.memory.load(elf.symbols['sink'], 8).symbolic:
        print('get!!')
        u1 = u

print(u1.posix.dumps(0))

