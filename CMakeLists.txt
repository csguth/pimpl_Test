cmake_minimum_required(VERSION 2.8)

project(pimpl_Test)
set (CMAKE_CXX_STANDARD 11)
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} cmake_modules)

unset(GRAPH_IMPL)

if(USE_BOOST)

    find_package(Boost)
    if(Boost_FOUND)

        set(GRAPH_IMPL boost_graph.cpp)

    endif()

else()

    find_package(LEMON)

    if(LEMON_FOUND)
        set(GRAPH_IMPL lemon_graph.cpp)
    endif()

endif()

add_executable(${PROJECT_NAME}
    ${GRAPH_IMPL}
    main.cpp
    )

if(LEMON_FOUND)
    target_link_libraries(${PROJECT_NAME} ${LEMON_LIBRARIES})
endif()
