! Solve 2023-10-02

! 터미널에 아래를 차례대로 입력
! cd baekjoon_all
! cd 10000+
! gfortran boj_10952.f90
! ./a.out

program boj_10952
    implicit none
    integer :: a, b

    do
        read *, a, b

        if (a == 0 .AND. b == 0) exit

        write (*, '(i0)') a + b
    end do

end program boj_10952
