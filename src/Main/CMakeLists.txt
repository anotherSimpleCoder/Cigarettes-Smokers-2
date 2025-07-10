add_executable(Main
	Main.cc
)

target_link_libraries(Main
	Smoker
	Distributor
	CS_Context
)
