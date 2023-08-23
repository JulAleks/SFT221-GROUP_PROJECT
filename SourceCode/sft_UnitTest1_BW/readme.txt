This is the tester environment for black box and white box. 
Properties: libraries, dependencies are added. 

Please be very careful with configuring any property values of this project. 
May result in linking errors.

Current property values:
Target Name:	$(ProjectName)

c/c++ Additional Include Directories:
	$(ProjectDir)..\project-starter
	$(VCInstallDir)UnitTest\include

linker general, Additional Library Directories:
	$(ProjectDir)..\project-starter
	$(ProjectDir)..\project-starter\x64\Debug
	$(VCInstallDir)UnitTest\lib

linker Input, Additional Dependencies:
	$(ProjectDir)..\project-starter\x64\Debug\mapping.obj
	$(ProjectDir)..\project-starter\x64\Debug\input.obj
	$(ProjectDir)..\project-starter\x64\Debug\main.obj
	$(ProjectDir)..\project-starter\x64\Debug\converting_function.obj
	