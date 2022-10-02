# Index
1. [Win64 Build](#-Window-Build-Dependency)
2. [Linux Build](#-Linux-Build-Dependency)

# Win64

### Window Build Dependency
- Perl 5.32 64bit
- NASM 2.15.05
- openssl 1.1.1p
- curl 7.85
- Visual Studio 2019(VC 16)

### Window MSVC Build

**1. perl 설치**
- https://strawberryperl.com/
- 설치 시 환경 변수 자동으로 추가 되지만, 
Path 환경 변수에 신규로 설치한 perl이 있는 bin 경로보다 
C:\msys64\usr\bin 경로가 상단에 있을 경우 우선순위 변경 필요.
 
**2. nasm 설치**
- x86 CPU 아키텍처용 어셈블러 NASM(Netwide Assembler) 설치
- https://www.nasm.us/
- 환경 변수 추가 필요.

**3. openssl 설치**
- https://github.com/openssl/openssl/releases/tag/OpenSSL_1_1_1p

**4. openssl MSVC로 build**
- 1\) 먼저, 64bit로 빌드할 것이므로 "x64 Native Tools Command Prompt for VS 2019"를 관리자 권한으로 실행
- 2\) VS 2019 prompt 환경에서, 설치한 openssl root 경로로 이동 후 perl Configure VC-WIN64A --openssldir=C:\OpenSSL-x64 no-shared no-asm threads no-idea no-mdc2 no-rc5 입력
- 3\) nmake 입력
- 4\) nmake test 입력
- 5\) nmake install 입력
- 6\) 빌드 완료 (C:\Program Files\OpenSSL 경로에 bin, lib, include, html 디렉토리 확인)

**5. libcurl 설치**
- https://github.com/curl/curl/releases/tag/curl-7_85_0

**6. libcurl build**
- 1\) 설치한 libcurl root 경로에서 buildconf.bat 실행
- 2\) winbuild 디렉토리로 이동
- 3\) 아래와 같은 구조 만든 후 _dep 디렉토리에 C:\Program Files\OpenSSL 경로의 bin, lib, include를 복사 
    ```
    somedirectory\
     |_curl-src
     |  |_winbuild
     |
     |_deps
        |_ lib
        |_ include
        |_ bin
    ``` 
- 3\) nmake /f Makefile.vc mode=static VC=16 WITH_DEVEL=../deps MACHINE=x64 WITH_PREFIX=builds
- 4\) 빌드 완료 ( winbuild/builds 디렉토리 확인)


# Linux

### Linux Build Dependency
- openssl 1.1.1p
- gcc 9.4
- Ubuntu 20.04.1
- curl 7.85

### Linux Build

**1. openssl 설치**
- https://github.com/openssl/openssl/releases/tag/OpenSSL_1_1_1p

**2. openssl build**
- ./config no-shared [no-zlib] (zlib 선택 사항)
- make 입력
- sudo make install 입력
- /usr/local/lib 경로에 libcrypto, libssl 확인 (.so, .a)

**3. libcurl 설치**
- https://github.com/curl/curl/releases/tag/curl-7_85_0

**4. libcurl build**
- ./configure --disable-shared [--without-zlib] --with-openssl 입력 (zlib 선택 사항)
- make 입력
- make test 입력(선택 사항)
- sudo make install 입력
- /usr/local/lib 경로에 libcurl 확인 (.so, .a)

**5. 주의사항**
- cmake curl, ssl, crypto linking 할 때 순서 주의