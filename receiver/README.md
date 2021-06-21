##**RECEIVER**

The Receiver Object is represented with the help of BmsReceiver class in "/receiver/BmsReceiver.java"

In java, we need a main method as the entry point when executing class from command line. 

So, here entry point is this method: public static void main(String[] arg) {.....}

Data streams coming from Sender will be read line by line and maximum/minimum will be find out on the basis of data read so far.

Simple moving average is calculated after we read at least 5 lines from Sender

BmsReceiverTask Object is used to handle all the tasks that Receiver should handle

For unit tests, we have BmsReceiverTest class
