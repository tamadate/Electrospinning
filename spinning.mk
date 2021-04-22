##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=spinning
ConfigurationName      :=Debug
WorkspacePath          := "/home/tama/spinning_simulation"
ProjectPath            := "/home/tama/spinning_simulation/spinning"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=tama
Date                   :=22/04/21
CodeLitePath           :="/home/tama/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="spinning.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/compute_force.cpp$(ObjectSuffix) $(IntermediateDirectory)/coul.cpp$(ObjectSuffix) $(IntermediateDirectory)/dragforce.cpp$(ObjectSuffix) $(IntermediateDirectory)/Efield.cpp$(ObjectSuffix) $(IntermediateDirectory)/surface_tension.cpp$(ObjectSuffix) $(IntermediateDirectory)/verlet.cpp$(ObjectSuffix) $(IntermediateDirectory)/viscoelastic.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/compute_force.cpp$(ObjectSuffix): compute_force.cpp $(IntermediateDirectory)/compute_force.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tama/spinning_simulation/spinning/compute_force.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compute_force.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/compute_force.cpp$(DependSuffix): compute_force.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/compute_force.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/compute_force.cpp$(DependSuffix) -MM "compute_force.cpp"

$(IntermediateDirectory)/compute_force.cpp$(PreprocessSuffix): compute_force.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/compute_force.cpp$(PreprocessSuffix) "compute_force.cpp"

$(IntermediateDirectory)/coul.cpp$(ObjectSuffix): coul.cpp $(IntermediateDirectory)/coul.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tama/spinning_simulation/spinning/coul.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/coul.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/coul.cpp$(DependSuffix): coul.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/coul.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/coul.cpp$(DependSuffix) -MM "coul.cpp"

$(IntermediateDirectory)/coul.cpp$(PreprocessSuffix): coul.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/coul.cpp$(PreprocessSuffix) "coul.cpp"

$(IntermediateDirectory)/dragforce.cpp$(ObjectSuffix): dragforce.cpp $(IntermediateDirectory)/dragforce.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tama/spinning_simulation/spinning/dragforce.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/dragforce.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/dragforce.cpp$(DependSuffix): dragforce.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/dragforce.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/dragforce.cpp$(DependSuffix) -MM "dragforce.cpp"

$(IntermediateDirectory)/dragforce.cpp$(PreprocessSuffix): dragforce.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/dragforce.cpp$(PreprocessSuffix) "dragforce.cpp"

$(IntermediateDirectory)/Efield.cpp$(ObjectSuffix): Efield.cpp $(IntermediateDirectory)/Efield.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tama/spinning_simulation/spinning/Efield.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Efield.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Efield.cpp$(DependSuffix): Efield.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Efield.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Efield.cpp$(DependSuffix) -MM "Efield.cpp"

$(IntermediateDirectory)/Efield.cpp$(PreprocessSuffix): Efield.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Efield.cpp$(PreprocessSuffix) "Efield.cpp"

$(IntermediateDirectory)/surface_tension.cpp$(ObjectSuffix): surface_tension.cpp $(IntermediateDirectory)/surface_tension.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tama/spinning_simulation/spinning/surface_tension.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/surface_tension.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/surface_tension.cpp$(DependSuffix): surface_tension.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/surface_tension.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/surface_tension.cpp$(DependSuffix) -MM "surface_tension.cpp"

$(IntermediateDirectory)/surface_tension.cpp$(PreprocessSuffix): surface_tension.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/surface_tension.cpp$(PreprocessSuffix) "surface_tension.cpp"

$(IntermediateDirectory)/verlet.cpp$(ObjectSuffix): verlet.cpp $(IntermediateDirectory)/verlet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tama/spinning_simulation/spinning/verlet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/verlet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/verlet.cpp$(DependSuffix): verlet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/verlet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/verlet.cpp$(DependSuffix) -MM "verlet.cpp"

$(IntermediateDirectory)/verlet.cpp$(PreprocessSuffix): verlet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/verlet.cpp$(PreprocessSuffix) "verlet.cpp"

$(IntermediateDirectory)/viscoelastic.cpp$(ObjectSuffix): viscoelastic.cpp $(IntermediateDirectory)/viscoelastic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tama/spinning_simulation/spinning/viscoelastic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/viscoelastic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/viscoelastic.cpp$(DependSuffix): viscoelastic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/viscoelastic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/viscoelastic.cpp$(DependSuffix) -MM "viscoelastic.cpp"

$(IntermediateDirectory)/viscoelastic.cpp$(PreprocessSuffix): viscoelastic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/viscoelastic.cpp$(PreprocessSuffix) "viscoelastic.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tama/spinning_simulation/spinning/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


