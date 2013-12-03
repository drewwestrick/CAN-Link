
/**
 * Module dependencies.
 */

var express = require('express');
var routes = require('./routes');
var user = require('./routes/user');
var http = require('http');
var path = require('path');
var serialport = require("serialport");
var SerialPort = serialport.SerialPort;

var serialPort = new SerialPort("/dev/ttyAMA0", {
  baudrate: 38400
});

var app     = express();
var server  = require('http').createServer(app);
var io      = require('socket.io').listen(server);

io.set('log level', 1);

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

// all environments
app.set('port', process.env.PORT || 80);
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'jade');
app.use(express.favicon());
app.use(express.logger('dev'));
app.use(express.json());
app.use(express.urlencoded());
app.use(express.methodOverride());
app.use(app.router);
app.use(require('stylus').middleware(path.join(__dirname, 'public')));
app.use(express.static(path.join(__dirname, 'public')));

// development only
if ('development' == app.get('env')) {
  app.use(express.errorHandler());
}

app.get('/', routes.index);
app.get('/users', user.list);

server.listen(app.get('port'));
