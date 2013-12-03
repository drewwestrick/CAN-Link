<h2>CAN-Link Introduction

<p>In the last few months I have found myself working on a lot of project that require the use of a CAN Network. Diagnosing CAN problems and viewing information on the network is often an important part of my job. This is why I decided to create a network capable utility that can interface with any CAN 2.0b network.

<h2>Freescale Processor - CAN Network

<p>At the heart of the CAN Link project is an ARM M4 Freescale processor. This processor acts at the intermediate layer between the Raspberry Pi and the physical CAN network. The development kit that I was working with has an onboard CAN transceiver and decoder. This processor has on onboard FPU so it can perform advanced floating point math very quickly if needed. There are configuration variables in the CAN processor code that allow the CAN data to be scaled and offset as needed. Once the information is captured via the Freescale ARM processor it is decoded, formatted and then passed out via an onboard UART running at 38,400 baud. This is how the information is transferred from the Freescale processor to the Raspberry Pi application processor.

<h4>Here is a simple bitmap example used to decode a CAN network message:

```C
typedef struct {
	float Signal_1;
	float Signal_2;
	float Signal_3;
	float Signal_4;
} CAN_MSG_1840_0x730_ProcessType;

typedef struct {
	uint8_t Signal_1;
	uint8_t Signal_2;
	uint8_t Signal_3;
	uint8_t Signal_4;
} CAN_MSG_1840_0x730_ProcessTypeInt;

typedef struct {
	struct {
		unsigned long long	Signal_1: 		8;	/* S:0   L:16  */
		unsigned long long 	Signal_2: 		8;	/* S:16  L:16  */
		unsigned long long	Signal_3: 		8;	/* S:32  L:16  */
		unsigned long long	Signal_4: 		8;	/* S:48  L:16 */
	} Msg;
	CAN_MSG_1840_0x730_ProcessType Factor;
	CAN_MSG_1840_0x730_ProcessType Offset;
	CAN_MSG_1840_0x730_ProcessTypeInt Value;
} CAN_MSG_1840_0x730_Type;
```

<h2>Server Side - Raspberry Pi Processor

<p>Once the data has been captured and formatted is comes into the Raspberry Pi via its onboard UART transceiver. The main operating system that runs on the raspberry pi is a Debian variant called Raspbian. Running on the operating system is a server side program called NodeJs. NodeJs is a server side javascript engine. Since Node runs on the server side it is able to access and interface with the onboard UART. The nice thing about Node is that it is decided to high throughput asynchronous communications. This makes it a perfect fit as this system will need to handle a larger amount of data that may come at any time over the CAN network. During testing of the system I was able to run multiple CAN messages at 1000 times a second. The Raspberry Pi running Node was more than capable to handle this data load. 

<h2>NodeJs Application

<p>Once the data is read in via the NodeJs server side script it is sent over to the client via a web socket connection. Again this connection is asynchronous and non-blocking. This allows multiple clients to be connected at once and receive data in near real time. One the client web application side the messages that we sent via the web socket from the server side are received. jQuery is then used to parse the data and create the table elements needed to display the messages. If a message already exists it is updated, otherwise a new row in the table is created.

<h4>Get the UART message and send via Socket.io:

```javascript
function Message(data) {
    this.Id = data[0]+(data[1]<<8);
    this.Len = data[2]
    this.Data = data.slice(3,3+this.Len);
}

serialPort.on("open", function () {
    console.log('open');
    serialPort.on('data', function(data) { 
        var Pkt = new Message(data); 
        io.sockets.emit('Pkt', JSON.stringify(Pkt));
    });
});
```

<h2>Conclusion

<p>The overall benefit to this system is the fact that the CAN network is now internet connected. With a few modifications to the code this data can be send up to a log server that can save the data for later analysis and use. This system also allows program managers and engineers to monitor test data remotely. Overall I think this CAN Link program will come in use on future projects.

