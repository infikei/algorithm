! Solve 2023-10-02

! 터미널에 아래를 차례대로 입력
! cd baekjoon_all
! cd 10000+
! gfortran boj_10951.f90
! ./a.out

program boj_10951
    implicit none
    integer :: a, b, stat

    do
        read (*, *, iostat=stat) a, b

        if (stat /= 0) exit

        write (*, '(i0)') a + b
    end do

end program boj_10951
