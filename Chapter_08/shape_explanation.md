# Object-Oriented Programming Concepts in `shape.cpp`

This write-up breaks down how I implemented core Object-Oriented Programming (OOP) concepts—like abstract classes, inheritance, chained inheritance, encapsulation, and polymorphism in my `shape.cpp` program for this assignment.

---

## 1. Abstract Class & Base Class (`Shape`)

* **Base Class:** The program starts with `Shape`, which acts as the base class for everything else.
* **Protected Variables:** It holds two protected member variables, `area` and `perimeter`, so that derived classes can access them directly.
* **Pure Virtual Functions:** It has two pure virtual functions:
  * `double calculate_area()`
  * `double calculate_perimeter()`
* Because these functions are purely virtual (set to `= 0`), **`Shape` becomes an abstract class**. This means you can't instantiate a `Shape` object directly in main.
* **Public Utility Functions:** It also includes standard public methods, `print_area()` and `print_perimeter()`, to print out the final calculated values to the console.

---

## 2. Inheritance (`Polygon`)

* **Derived Class:** `Polygon` inherits publicly from `Shape` (`class Polygon : public Shape`).
* **Inherited Attributes:** Since `Polygon` is a child of `Shape`, it automatically gets attributes like `area` and `perimeter` from its parent. This shows standard **inheritance**.
* **Members:**
  * **Private:** `number_of_sides` (keeps track of how many sides the shape has).
  * **Protected:** `sides` (a `vector<double>` that stores the length of each side).

---

## 3. Chained Inheritance (`Square`)

* **Multi-level Structure:** `Square` is derived from `Polygon`, which is derived from `Shape`
 (`Square`-> `Polygon`->`Shape`).
* **Passing down attributes:** Because of this chain, `Square` doesn't just inherit attributes and methods from `Polygon`—it also gets everything passed down from `Shape`.
* This setup gives us a clear example of **chained inheritance**.

---

## 4. Encapsulation

* **Data Hiding:** Encapsulation is used here to keep certain data protected from direct access outside the class.
* For instance, `number_of_sides` is set as a **private** member inside `Polygon`.
* This means code outside `Polygon` (like functions in `main`) cannot directly touch or corrupt `number_of_sides`—it can only be updated or interacted with through internal class logic.

---

## 5. Polymorphism (Runtime Polymorphism)

* The code demonstrates **runtime polymorphism** through virtual functions, allowing different derived classes to override methods while using a common base interface.
* **Overriding Behaviors:**
  * `calculate_perimeter()` is defined and customized inside `Polygon` to sum up all side lengths in the vector.
  * `calculate_area()` is defined and overridden in `Square` to calculate area using $side^2$ (`sides[0] * sides[0]`).
* Even though both functions share the exact same declaration signature defined back in `Shape`, their actual behavior changes depending on which derived class is calling them.
AI use
I used Gemini AI to edit this md such that I capture all the attributes articulately and also for the formatting since I do not know how to do that