[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/kkuchar2/rose">
    	🌹
  </a>

  <h3 align="center">rose</h3>

  <p align="center">
    Set of classes in C++, C# and Java implementing too simple  observer pattern
    <br />
    <br />
    <a href="https://github.com/kkuchar2/rose/issues">Report Bug</a>
        ·
    <a href="https://github.com/kkuchar2/rose/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
* [Getting Started](#getting-started)
* [Usage](#usage)
* [Contributing](#contributing)
* [License](#license)

<!-- ABOUT THE PROJECT -->
## About The Project

This is simple project implementing observer patter in C++, C# and Java, that I use in personal and professional work.


<!-- GETTING STARTED -->
## Getting Started

1. Clone the repo

  ```sh
  git clone https://github.com/kkuchar2/rose
  ```

2. Choose your language and copy related files to your project.
```sh
rose
│
└───csharp   { copy content of this directory to your project }
│
└───cpp      { copy content of /src to your project or use CmakeLists.txt }
│
└───java     { copy whole package in main or build .jar }
    │
    │    pom.xml
    └─── src
         └─── test
         └─── main
               └─── com.kkuchar2.rose
```

## Usage

#### C++

```c++
#include "Rose/Property/IntegerProperty.h"

int main() {

  // Define observable

  IntegerProperty integerProperty(0);

  // Define observer

  Observer<int> observer = createObserver<int>(([](auto v) { println(v * 2.25236); }));

  // Subscribe to observable change and register subscription

  Subscription subscription = integerProperty.Subscribe(observer);

  // Change value of observable

  for (int i = 0; i <= 5; i++) {
       integerProperty.setValue(i);
  }

  // Unsubscribe at the end

  subscription->Unsubscribe();

  return 0;
}
```


Output:
```console
2.25236
4.50472
6.75708
9.00944
11.2618
```

#### Java

```Java
import com.kkuchar2.rose.SubscriptionContainer;
import com.kkuchar2.rose.properties.IntegerProperty;

public class Main {

    public static void main(String[] args) {

      IntegerProperty property = new IntegerProperty(0);

      Subscription subscription = property.addObserver(v -> System.out.println(v * 2.25236));

      for (int i = 0; i <= 5; i++) {
          property.setValue(i);
      }

      subscription.unsubscribe();
    }
}
```

Output:
```console
2.25236
4.50472
6.75708
9.00944
11.2618
```


#### C# #

```csharp
using System;
using Rose;

namespace ConsoleApp1 {

    class Program {

        static void Main(string[] args) {

            IntegerProperty property = new IntegerProperty(0);

            Subscription s = property.AddObserver(v => Console.WriteLine(v * 2.25236));

            for (int i = 0; i <= 5; i++) {
                property.Value = i;
            }

            s.Unsubscribe();
        }
    }
}
```

Output:
```console
2.25236
4.50472
6.75708
9.00944
11.2618
```


## Contributing

Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/kkuchar2/rose.svg?style=flat-square
[contributors-url]: https://github.com/kkuchar2/rose/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/kkuchar2/rose.svg?style=flat-square
[forks-url]: https://github.com/kkuchar2/rose/network/members
[stars-shield]: https://img.shields.io/github/stars/kkuchar2/rose.svg?style=flat-square
[stars-url]: https://github.com/kkuchar2/rose/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=flat-square
[issues-url]: https://github.com/kkuchar2/rose/issues
[license-shield]: https://img.shields.io/github/license/kkuchar2/rose?style=flat-square
[license-url]: https://github.com/kkuchar2/rose/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/kkuchar/
[product-screenshot]: images/screenshot.png
