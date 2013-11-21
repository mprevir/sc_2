project( sc2 )

cmake_minimum_required( VERSION 2.8.6 )

set( CMAKE_AUTOMOC true )

find_package( Qt4 REQUIRED QtGui QtCore )

include( ${QT_USE_FILE} )

add_subdirectory(AANN)

add_definitions( -std=c++0x )

file( GLOB SOURCES "*.cxx" )

include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

qt4_wrap_ui( matrixdialogFORM "matrixdialog.ui")

add_executable( sc2 ${SOURCES} ${matrixdialogFORM} )

target_link_libraries( sc2 ${QT_LIBRARIES} AssociativeANN)
