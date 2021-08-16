1) Use command below to extract the files in the jar
"jar xvf KhaiPhan_a1"

2) to execute the classes file, I only need to run the one in the main which located in this folder:
./src/com.btp400/FinancialApp.java.
Assume that after you have extract the jar file, you are standing at that current location
"javac -cp ./com/btp400/*.java ./com/seneca/accounts/*.java ./com/seneca/business/*.java"

3) to run the app, I use this command:
"java -cp KhaiPhan_a1.jar com.btp400.FinancialApp"
