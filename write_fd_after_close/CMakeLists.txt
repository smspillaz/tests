set (FOO 1)
set (BAR 1)
set (BAZ 0)

set (FOO_BAR FOO AND BAR)
set (FOO_BAR_BAZ FOO AND BAR AND BAZ)

if (FOO_BAR)

    message ("FOO_BAR")

endif ()

if (FOO_BAR_BAZ)

    message ("FOO_BAR_BAZ")

endif ()
