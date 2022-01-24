# **Get_next_line**

##### Reading a line on a fd is way too tedious

**이 프로젝트의 목적은 파일 디스크립터로부터 읽혀진, 개행으로 끝나는 한 줄을 반환하는 함수를 코드화 하는 것입니다.**

<br>

## Info
- #### _int	open(const char *filepath, int flag, mode_t mode)_
    include<fcntl.h>
    
    filepath : 파일경로, flag : 파일열기 옵션, mode : 파일권한(O_CREAT 사용시 필수)
    
    O_RDONLY : 읽기모드, O_WRONLY : 쓰기모드, O_RDWR : 읽기/쓰기모드, O_CREAT : 파일생성, O_TRUNC : 파일 초기화, O_APPEND : 기존 파일의 맨 끝부터 이어쓰기, O_EXCL : O_CREAT와 함께 사용, 기존 파일 존재시 에러 리턴
    
    mode_t mode default value : file - 0666, directory - 0777
    
    return value : 성공시 0, 실패시 -1

- #### _ssize_t	read(int fd, void *buf, size_t n)_
    include<unistd.h>
    
    fd : 파일드스크립터, buf : 파일을 읽어 들일 버퍼, n : 버퍼 크기
    
    실패시 -1, 정상적으로 실행됐다면 읽어들인 바이트 반환

- #### _fd(File Descriptor), value : 0 ~ OPEN_MAX(플랫폼마다 상이, mac = 2560)_
    linux의 시스템에서 프로세스가 파일을 다룰 때 사용하는 추상적인 값 또는 테이블 인덱스
    
    프로세스에 의해 파일을 open하면 커널은 해당 프로세스 fd 중 사용하지 않는 가장 작은 값 할당
    
    프로세스는 fd테이블 및 파일 테이블 정보를 직접 수정 불가하며 반드시 커널을 통해야 수정 가능
    
    커널 구조체 중 struct files_struct의 struct file fd_array란 배열 존재

    fd_array는 각각 file 구조체의 f_dentry(directory entry)를 가리킴, f_dentry : linux에서 디렉토리에 접근을 빠르게 하기 위한 구조체
    
    f_dentry는 관련된 inode 구조체를 가리키는 필드 포함, inode : 파일종류와 권한, lock 목록 포안터, 여러 파일 오퍼레이션과 다양한 파일 속성등
    
    POSIX 표준 STDIN_FILENO : 0, STDOUT_FILENO : 1, STDERR_FILENO : 2

- #### _off_t	lseek(int fd, off_t offset, int whence)_
    #include<sys/types.h>, #include<unistd.h>
    
    offset : 기준위치로부터 상대적 변위, 기준에 따라 음수가능

    whence : 기준위치

    SEEK_SET : 파일의 처음, SEEK_CUR : 현재위치, SEEK_END : 파일의 끝
    
    return value : 성공시 파일의 처음을 기준으로 포인터의 오프셋 반환, 실패시 -1
    
    sparse(희소) : 의미있는 데이터가 드물게 나타낼 때 대부분의 데이터가 '0'으로 채워져있음을 의미

<br>
