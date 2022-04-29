DOCUMENATION
============

The following is the listing of all supported routes and methods by the API.
The API is broken down into the different actions

Custom headers
--------------

When submitting a GET request to the `/proc` endpoints,
you can specify the `Accept:` header and choose
exactly what format you would like back. The API accepts the following mime
types

* `application/json`
  * *Default response*
  * Returns as a json dictionary with sensible keys
* `text/plain`
  * Returns exact response from the `/proc` file system
  * For more about the format of these responses, refer to the proc(5) manpage

Security tokens
---------------

The application provides the `-a` flag, which accepts a path as a required
argument. The file specified in the path should contain a series of strings,
each on a new line. Each line represents a valid token that the client can send
to authorize the request. This token must be send in a `Authorization:` header.
If the token is not given, or the wrong token is given, the server will instead
return a 403.

Proc file responses
============

[GET] /proc/uptime
-------------

* returns uptime and idle time
* Same as /proc/uptime file

Sample response

```
{
  "uptime": 72583.24
  "idle" : 834157.72
}
```

[GET] /proc/meminfo
-------------------

* returns infomration regarding system memory
* All responses are in kB
* Same as /proc/meminfo file

[GET] /proc/loadavg
-------------------

* returns system load averaged over 1, 5, and 10 mins
* returns number of currently running processes over the total number of
  process
* returns the last proccessed PID used
* Same as /proc/loadavg file

Sample response

```
{
  "1" : 0.56,
  "5" : 0.69,
  "10" : 1.30,
  "processes" : "2/849",
  "lastPID" : 28225,
}
```

[GET] /proc/sys/kernel/hostname
--------------------------------

* returns hostname
* Same as /proc/sys/kernel/hostname file

Sample response

```
{
  "hostname": "Samplebox"
}
```

Special formatted responses and aliases
===========================

[GET] /uptime
-------------

* Returns a redirect to /proc/uptime

[GET] /load
----------

* Returns a redirect to /proc/loadavg

[GET] /mem
----------

* returns memory usage
* formatted version of /proc/meminfo
* All responses are in kB

Sample response

```
{
  "memtotal" : 16255116,
  "memfree"  : 2127320,
  "memavailable" : 12324924,
}
```

[GET] /hostname
---------------

* Returns redirect to /proc/sys/kernel/hostname

[GET] /up
---------

* Always returns a 200 OK
* Can be used for testing latency
