! Solve 2023-10-02

! 터미널에 아래를 차례대로 입력
! cd baekjoon_all
! cd 11000+
! gfortran boj_11022.f90
! ./a.out

program boj_11022
    implicit none
    integer :: t, ti, a, b

    read *, t

    do ti = 1, t
        read *, a, b

        write (*, '(a, i0, a, i0, a, i0, a, i0)') "Case #", ti, ": ", a, " + ", b, " = ", a + b
    end do

end program boj_11022
