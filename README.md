# qtserverclient
Qt5 socket server and client, taliking to eachothers. CMake makes possible to build two executables in same Qt Creator project. <br>
Both excecutables can be executed from QtCreator
<br>
Server is grep expressing received message (integers)(chars)(integers), taking the last number to be used later for some UI stuff
(like measured and received temperature)

ROS2 based sender can be used messages to this server (   mnokka /
ROS2TalksSocketServer )
