set(
    HEADER_FILES
)

set(
    SOURCE_FILES
		main.cpp
)

add_executable(
    OrderedVisitor
        ${SOURCE_FILES}
        ${HEADER_FILES}
)

set_property( TARGET OrderedVisitor PROPERTY CXX_STANDARD 20 )
include_directories( ${PROJECT_ROOT_DIR} )

# Project libraries
#target_link_libraries(
#Burst PUBLIC
#Vkt
#)

### Libraries
