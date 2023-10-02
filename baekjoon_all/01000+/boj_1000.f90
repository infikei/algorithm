! Solve 2023-10-02

! 터미널에 아래를 차례대로 입력
! cd baekjoon_all
! cd 01000+
! gfortran boj_1000.f90
! ./a.out

program boj_1000
    implicit none
    integer :: a, b

    read *, a, b

    write (*, '(i0)') a + b

end program boj_1000
