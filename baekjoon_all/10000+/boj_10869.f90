! Solve 2023-10-02

! 터미널에 아래를 차례대로 입력
! cd baekjoon_all
! cd 10000+
! gfortran boj_10869.f90
! ./a.out

program boj_10869
    implicit none
    integer :: a, b

    read *, a, b

    write (*, '(i0)') a + b
    write (*, '(i0)') a - b
    write (*, '(i0)') a * b
    write (*, '(i0)') a / b
    write (*, '(i0)') mod(a, b)

end program boj_10869
