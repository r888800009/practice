pwd = $(shell pwd)
glibc_2.31:
	curl https://raw.githubusercontent.com/r888800009/CTF-tool/master/pwn_docker/Dockerfile > Dockerfile
	docker build . -t ubuntu2004 --target basic --build-arg VERSION=20.04

unsorted-bin: glibc_2.31
	docker run --rm -it -v $(pwd):/work ubuntu2004 /bin/sh -c "cd /work ; gcc unsorted-bin.c -g ; gdb -x unsorted-bin.py ./a.out"
