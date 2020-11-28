rem set path=c:\jdk1.3\bin;%path%

set ANT_HOME=c:\ant
set JAVA_HOME=c:\j2sdk1.4.1
set J2EE_HOME=c:\j2sdkee1.3

set OTHER_LIB=c:\java_lib\jaxp.jar;



set PATH=%JAVA_HOME%\bin;%J2EE_HOME%\bin;%ANT_HOME%\bin;%PATH%
set CLASSPATH=%CLASSPATH%;%JAVA_HOME%\jre\lib\rt.jar;%J2EE_HOME%\lib\j2ee.jar;.
set CLASSPATH=%CLASSPATH%;%OTHER_LIB%