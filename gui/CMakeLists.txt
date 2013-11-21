project( sc2 )

cmake_minimum_required( VERSION 2.8.6 )

set( CMAKE_AUTOMOC true )

find_package( Qt4 REQUIRED QtGui QtCore )

include( ${QT_USE_FILE} )

add_definitions( -std=c++0x )

file( GLOB SOURCES "*.cxx" )

add_executable( sc2 ${SOURCES} )

target_link_libraries( sc2 ${QT_LIBRARIES} )
