# Spring

Spring makes programming Java quicker, easier, and safer for everybody. Spring’s focus on speed, simplicity, and productivity has made it the world's most popular Java framework.

### Why?

* Spring is everywhere
* fast
* secure
* productive
* flexible 
* supportive

### When

* Microservicecs
* Reactive
* Cloud
* Web Apps
* Serverless
* Event Driven
* Batch

### Basic Model

At its core, Spring offers a `container`, often referred to as the Spring application context,
that creates and manages application `components`. These components, or `beans`,
are wired together inside the Spring application context to make a complete application,

The act of wiring beans together is based on a pattern known as dependency injection
(DI).Rather than have components create and maintain the lifecycle of other beans
that they depend on, a dependency-injected application relies on a separate entity
(the container) to create and maintain all components and inject those into the beans
that need them. This is done typically through constructor arguments or property
accessor methods.

##### Confguration

**by XML**

```
<bean id="inventoryService"
class="com.example.InventoryService" />
<bean id="productService"
class="com.example.ProductService" />
<constructor-arg ref="inventoryService" />
</bean>
```

**by Java**

_greater type safety and improved refactorability._

```
@Configuration
public class ServiceConfiguration {

  @Bean
  public InventoryService inventoryService() {
    return new InventoryService();
  }

  @Bean
  public ProductService productService() {
    return new ProductService(inventoryService());
  }
}
```

Automatic configuration has its roots in the Spring techniques known as `autowiring` and `component scanning`.

Spring Boot is an extension of the Spring Framework that offers several productivity enhancements. The most
well-known of these enhancements is `autoconfiguration`, where Spring Boot can make
reasonable guesses of what components need to be configured and wired together,
based on entries in the `classpath, environment variables, and other factors`.

### Spring Initializr

* (Web App)[http://start.spring.io]
* curl
* Spring Boot CLI
* Spring Tool Suite
* IntelliJ IDEA
* NetBeans

### Resourcess

* [Best learning resources for the Spring Framework (incl. Spring Boot): books, podcasts, YouTube channels, websites and video courses](https://rieckpil.de/essential-spring-developer-resources/)
* [Spring in Action by Crag Walls](https://www.manning.com/books/spring-in-action-fifth-edition)
* [Official guides](https://spring.io/guides)