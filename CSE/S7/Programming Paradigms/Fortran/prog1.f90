
program main
    implicit none

    integer :: i = 3, ret

    print *, "Value of 'i' in main, before the function call is : ", i
    ret = fun1()
    ! if value of 'i' in main changes, then it's static binding.
    print *, "Value of 'i' in main, after the function call is : ", i

    contains
    integer function fun2()
            implicit none
            i = 30                ! 'i' in main is changed here : static
    end function fun2

    integer function fun1()
            implicit none
            integer :: i = 20
            integer :: sum
            sum = fun2()
    end function fun1

end program main
