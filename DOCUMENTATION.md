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

Special formatted responses
===========================

[GET] /uptime
-------------

* Returns a redirect to /proc/uptime

[GET] /load
----------

* Returns load average over the past 1, 5, and 10 mins
* formatted version of /proc/loadavg

Sample response

```
{
  "1" : 0.56
  "5" : 0.69
  "10" : 1.30
}
```

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
