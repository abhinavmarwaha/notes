# let vs var

* var has no block scope
* var tolerates redeclarations
* var variables can be declared below their use
* **IIFE**: immediately-invoked function expressions

```
(function() {

  var message = "Hello";

  alert(message); // Hello

})();
```