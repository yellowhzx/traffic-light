**智能交通灯**
====================
> ##### *PCB还不够完善* *通过面包板搭配完成*

### 原理：stm32定时器定时1s，控制时间，oled通过iic协议与stm32通信作为显示，红外检测车辆是否通过

![图片1](https://github.com/yellowhzx/traffic-light/blob/main/%E7%A4%BA%E4%BE%8B1.jpg)  
![图片2](https://github.com/yellowhzx/traffic-light/blob/main/%E7%A4%BA%E4%BE%8B2.jpg)  

1.hrq里面放源码  
2.绘图1是流程图  
3.PCB文件放的板子原理图  

**原理图里面oled是老款的，封装错了，VCC与GND反了，插面包板上面，把两个脚换一下使用！！！！！！！！！！  
VCC与GND一定不要弄反，反了全都给你烧了。没反应可能就是电源接反或者烧坏了。**

另外欢迎大家访问我的[个人网站](https://www.yellowhzx.cn/)  
