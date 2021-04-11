
file(GLOB SRC_PMS 
  "pms/*.cc"
)

# Declare the library
add_library(pms STATIC ${SRC_PMS} ${UTILITY_SRC})

target_link_libraries(pms armadillo)

target_include_directories(pms
  PRIVATE "../include"
)