! Solve 2023-10-02

! 터미널에 아래를 차례대로 입력
! cd baekjoon_all
! cd 10000+
! gfortran boj_10950.f90
! ./a.out

program boj_10950
    implicit none
    integer :: t, ti, a, b

    read *, t

    do ti = 1, t
        read *, a, b

        write (*, '(i0)') a + b
    end do

end program boj_10950
