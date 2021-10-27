# use strict

To keep the old code working, most such modifications are off by default. You need to explicitly enable them with a special directive: "use strict". (at the top)

Modern JavaScript supports “classes” and “modules” – advanced language structures that enable use strict automatically. So we don’t need to add the "use strict" directive, if we use them.

```
"use strict";

// this code works the modern way
```

```
(function() {
  'use strict';

  // ...your code here...
})()
```