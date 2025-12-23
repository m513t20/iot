Данное задание было сделано вместе с **Егором Кузнецовым**, он отвечал за передачу - файлы
[publisher.py](./publisher.py) и [sensor.ino](./sensor.ino). В них микроконтроллер
считывал значения напряжение на цепи с фоторезистором и в зависимости от этого
отправлял команды в брокер. Пакетом или одиночным запросом.

Я отвечал за файлы [controller.ino](./controller.ino) и [subscriber.py](./subscriber.py)
в них через брокер принмалась команда и передавалась на микроконтроллер через uart
после чего ответ микроконтроллера выводился в консоль.

# Видео
* [Работа с пары](https://drive.google.com/file/d/143Otp4xfjesdhUsvJReQhGR4Wdv2nNFw/view?usp=sharing)
* [Передача](https://drive.google.com/file/d/1N_DBNIPk1Q0YjAfKF1Gvlj-qpbTb53e7/view?usp=sharing)
* [Прием](https://drive.google.com/file/d/1ebw3iQPCPKbs8g-yl3uwQomoN4mZybS-/view?usp=sharing)
