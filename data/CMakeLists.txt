##
##  Systemd Unit File
##

# where to install
# Uncomment when we drop Vivid
# pkg_get_variable(SYSTEMD_USER_DIR systemd systemduserunitdir)
set (SYSTEMD_USER_DIR "/usr/lib/systemd/user")
message (STATUS "${SYSTEMD_USER_DIR} is the systemd user unit file install dir")

set (SYSTEMD_USER_NAME "${CMAKE_PROJECT_NAME}.service")
set (SYSTEMD_USER_FILE "${CMAKE_CURRENT_BINARY_DIR}/${SYSTEMD_USER_NAME}")
set (SYSTEMD_USER_FILE_IN "${CMAKE_CURRENT_SOURCE_DIR}/${SYSTEMD_USER_NAME}.in")

# build it
set (pkglibexecdir "${CMAKE_INSTALL_FULL_PKGLIBEXECDIR}")
configure_file ("${SYSTEMD_USER_FILE_IN}" "${SYSTEMD_USER_FILE}")

# install it
install (FILES "${SYSTEMD_USER_FILE}"
         DESTINATION "${SYSTEMD_USER_DIR}")

##
##  Upstart systemd override Job File
##

set (UPSTART_SYSTEMD_OVERRIDE_DIR "${CMAKE_INSTALL_FULL_DATADIR}/upstart/systemd-session/upstart")
message (STATUS "${UPSTART_SYSTEMD_OVERRIDE_DIR} is the Upstart override Job File for systemd dir")

install (FILES "${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_PROJECT_NAME}.override"
         DESTINATION "${UPSTART_SYSTEMD_OVERRIDE_DIR}")

##
##  Upstart Job File
##

# where to install
set (UPSTART_JOB_DIR "${CMAKE_INSTALL_FULL_DATADIR}/upstart/sessions")
message (STATUS "${UPSTART_JOB_DIR} is the Upstart Job File install dir")

set (UPSTART_JOB_NAME "${CMAKE_PROJECT_NAME}.conf")
set (UPSTART_JOB_FILE "${CMAKE_CURRENT_BINARY_DIR}/${UPSTART_JOB_NAME}")
set (UPSTART_JOB_FILE_IN "${CMAKE_CURRENT_SOURCE_DIR}/${UPSTART_JOB_NAME}.in")

# build it
set (pkglibexecdir "${CMAKE_INSTALL_FULL_PKGLIBEXECDIR}")
configure_file ("${UPSTART_JOB_FILE_IN}" "${UPSTART_JOB_FILE}")

# install it
install (FILES "${UPSTART_JOB_FILE}"
         DESTINATION "${UPSTART_JOB_DIR}")

##
##  Unity Indicator File
##

# where to install
set (UNITY_INDICATOR_DIR "${CMAKE_INSTALL_FULL_DATAROOTDIR}/unity/indicators")
message (STATUS "${UNITY_INDICATOR_DIR} is the Unity Indicator install dir")

set (UNITY_INDICATOR_NAME "com.canonical.indicator.transfer")
set (UNITY_INDICATOR_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${UNITY_INDICATOR_NAME}")

install (FILES "${UNITY_INDICATOR_FILE}"
         DESTINATION "${UNITY_INDICATOR_DIR}")

##
## Pkg dev file
set (INDICATOR_PKG_NAME "${CMAKE_PROJECT_NAME}.pc")
set (INDICATOR_PKG_FILE "${CMAKE_CURRENT_BINARY_DIR}/${INDICATOR_PKG_NAME}")
set (INDICATOR_PKG_FILE_IN "${CMAKE_CURRENT_SOURCE_DIR}/${INDICATOR_PKG_NAME}.in")
configure_file ("${INDICATOR_PKG_FILE_IN}" "${INDICATOR_PKG_FILE}" @ONLY)
install (FILES "${INDICATOR_PKG_FILE}"
         DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig")
