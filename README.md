# 🧐 Bureaucrats-CPP05 ![Static Badge](https://img.shields.io/badge/Barcelona-black?style=for-the-badge&logo=42&logoColor=%23FFFFFF)
![Static Badge](https://img.shields.io/badge/C++-blue?style=flat&logo=cplusplus)
![Static Badge](https://img.shields.io/badge/Makefile-green?style=flat&logo=AnkerMake)
![Static Badge](https://img.shields.io/badge/status-completed-green?style=flat)

This project introduces **abstract classes, inheritance, polymorphism, and exceptions** in C++.

It simulates a bureaucratic system where bureaucrats can sign and execute forms depending on their grades. Each form has specific requirements and performs a different action.

## Classes

- **Bureaucrat:** Represents a bureaucrat with a name and a grade. The grade determines whether they can sign or execute a form. Grades range from 1 (highest) to 150 (lowest).

- **AForm:** An abstract base class for all forms. It stores the form's name, signing status, and the grades required to sign and execute it. It also checks permissions before allowing a form to be signed or executed.

- **ShrubberyCreationForm:** Inherits from `AForm`. When executed, it creates a file containing ASCII trees. It requires the form to be signed and the bureaucrat to have a sufficiently high grade.

- **RobotomyRequestForm:** Inherits from `AForm`. It simulates a robotomy operation on a target, with a 50% chance of success.

- **PresidentialPardonForm:** Inherits from `AForm`. It pardons a target in the name of Zaphod Beeblebrox.

## How the Classes Work Together

`AForm` defines the common rules that all forms must follow. The three specific forms inherit from it and implement their own execution behavior.

`Bureaucrat` interacts with forms by signing or executing them. Before an action is performed, the required grade and signing status are checked. If these requirements are not met, the program throws an exception.

This structure avoids repeating common code and demonstrates **inheritance and polymorphism**: all forms share the same base class but behave differently when executed.

## Instructions

Compile the project using Make:

```bash
make
```

Run the program:

```bash
./main
```

Clean the generated files:

```bash
make clean
```

Remove all compiled files and the executable:

```bash
make fclean
```

The project is written in **C++98** and uses a **Makefile** for compilation.