# PROJECT Remote glove ([EN](Readme.md) | [BG](README.bg.md))

![img_1.png](icon.png) \
Идеята е нашият проект да представлява **РЪКАВИЦА**, която се свързва към телевизора посредством Блутут и движейки я наляво-надясно имитира дистанционно. Могат да се управляват каналите и звука чрез инфрачервен диод и да се движи курсора на мишката, ако сте в някое онлайн приложение. \
Проектът ни е разделен на 2 части - блутут приемник и блутут предавател. Приемника се свързва към телевизора  и веднага бива разпознат като мишка. След това предавателя, който е в ръкавицата осъществява връзката с приемника. Контрола на курсора на мишката става като се изпращат сигнали от акселерометър, свързан към предавателя.
<br>
### Защо?
**Целта на нашия проект е да разработим едно по-функционално и иновативно дистанционно(ръкавица)** за телевизор и най-вече да улесни хората, гледащи YouTube или Netflix, като предостави лесен и удобен механизъм, за управление на курсора на мишката. \
Сегашните дистанционни за телевизор не са се променили много от последните 10 години. Те предоставят добър метод за управление на каналите и базовите функционалности на телевизора, но с напредването на технологиите производителите правят и продават - така наречените "smart TV", които имат достъп до интернет и приложения като интернет browser, youtube, netflix. Навигацията за тези приложения обаче, все още не е интегрирана добре и тук се намесва нашият продукт!

## Компоненти:
- **C++** with **Arduino IDE** for code setup
- MPU 6050
- 2 x arduino micro
- bluetooth module HC-05 at master mode
- bluetooth module HC-06 at slave mode
- 2 x standard buttons
- 2 x 2k ohms resistors

<br><br>
### Кои сме ние?

Ние сме двама единадесетокласници, които търсят и искат да създадат нещо ново \
<br>**Stoyan Tinchev** - *програмист, хардуерист* \
**Daniel Rogachev** - *програмист, направи схемата на проекта*