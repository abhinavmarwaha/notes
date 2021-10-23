# Proxy

lets you provide a substitute or placeholder for another object. A proxy controls access to the original object, allowing you to perform something either before or after the request gets through to the original object.

### When?

* Lazy initialization (virtual proxy). This is when you have a heavyweight service object that wastes system resources by being always up, even though you only need it from time to time.
* Access control (protection proxy). This is when you want only specific clients to be able to use the service object; for instance, when your objects are crucial parts of an operating system and clients are various launched applications (including malicious ones).
* Local execution of a remote service (remote proxy). This is when the service object is located on a remote server.
* Logging requests (logging proxy). This is when you want to keep a history of requests to the service object.
* Caching request results (caching proxy). This is when you need to cache results of client requests and manage the life cycle of this cache, especially if results are quite large.
* Smart reference. This is when you need to be able to dismiss a heavyweight object once there are no clients that use it.

| Pros | Cons |
|------|------|
|You can control the service object without clients knowing about it.| The code may become more complicated since you need to introduce a lot of new classes.|
|You can manage the lifecycle of the service object when clients don’t care about it.| The response from the service might get delayed.|
|The proxy works even if the service object isn’t ready or is not available.|   |
|**Open/Closed Principle**: You can introduce new proxies without changing the service or clients.|   |