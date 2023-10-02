! Solve 2023-10-02

! 터미널에 아래를 차례대로 입력
! cd baekjoon_all
! cd 02000+
! gfortran boj_2558.f90
! ./a.out

program boj_2558
    implicit none
    integer :: a, b

    read *, a
    read *, b

    write (*, '(i0)') a + b

end program boj_2558
