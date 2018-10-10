# 用Construct 2制作一款简单的html游戏
>很多人都喜欢玩游戏,可是说到制作游戏,绝大多数人就开始挠头了,今天博主就向大家展示如何制作一款简单的html游戏。


## 一、下载并安装Construct 2
[点击这里](http：//www.scirra.com/construct2/releases/new)以下载最新版本的Construct 2
<br/>进入网页后点击Download即可下载
![](images\lab02\lab02的1.PNG)
## 二、新建一个项目
安装好Construct 2之后,进入程序,新建项目即可
![](images\lab02\GIF1.gif)

## 三、插入对象(背景、人物、效果等)
1. 首先应该寻找一张作为背景的图片博主选择的是大雄(哆啦A梦中人物)背景，如下图所示:
![](images\lab02\background.jpg)

2. 双击空白以插入对象,点击Tiled Background,点击insert以插入,出现十字准线后单击,会打开Edit texture,点击load an image from a file,找到背景图的位置,然后选择它,关闭Edit texture,调整背景以及布局(白色区域)的大小使其几乎重叠
![](images\lab02\GIF2.gif)

3. 添加图层Main,确保在图层栏中选择了“Main”图层。这很重要因为所选图层是活动图层。所有新插入的对象都插入到活动层中,因此如果未选中,我们将意外插入到错误的层。
![](images\lab02\GIF3.gif)

4. 添加输入对象,双击layout1空白处以插入另外的新对象,这次是Mouse和Keyboard。这些对象不需要放置在布局中。它们是隐藏的,并自动在项目范围内工作。现在我们项目中的所有布局都可以接受鼠标和键盘输入。
5. 插入游戏对象，比如**Player**(哆啦A梦)、**Monster**(老鼠，因为哆啦A梦的耳朵被老鼠咬掉了)、**Bullet**(哆啦A梦最喜欢的铜锣烧)、**Explosion**(爆炸效果)等。
![](images\lab02\GIF4.gif)

## 四、添加行为
1. 了解一些行为:
<br/>8 Direction movement:这使您可以使用箭头键移动对象。它会很好地适应玩家的运动。
<br/>Bullet movement:这只是以当前角度向前移动一个物体。它对玩家的子弹很有用。尽管有这个名字,它也可以很好地移动怪物,因为所有的移动都是以某种速度向前移动物体。
<br/>Scroll to:这使得屏幕在移动时跟随对象,这对玩家有用。
<br/>Bound to layout:这将停止一个物体离开布局区域。这对玩家也很有用,所以他们不能在游戏区域外游荡！
<br/>Destroy outside layout:而不是停止离开布局区域的对象,如果它停止,则会破坏它。它对我们的子弹很有用。没有它,子弹将永远飞离屏幕,总是占用一点内存和处理能力。相反,我们应该在他们离开布局后销毁子弹。
<br/>Fade:这逐渐使物体淡出,我们将用于爆炸。
2. 如何添加行为:
![](images\lab02\GIF5.gif)

3. 创建更多的Monster。按住Ctrl用鼠标拖动Monster以创建,七至八个即可。
![](images\lab02\lab02的2.PNG)

## 五、添加活动(Event)
1. 要想让Player一直看着鼠标,完成起来应该是这样。
![](images\lab02\GIF6.gif)

2. 同理你可以这样添加更多活动。
<br/>**让Player发射Bullet**:
<br/>Event: Mouse-->On click-->Left clicked (the default)
<br/>Action: Player-->Spawn another object-->For Object, choose the Bullet object.
<br/>**让Bullet杀死Monster**:
<br/>Event: Bullet-->On collision with another object-->pick Monster.
<br/>Action: Monster-->Destroy
<br/>Action: Bullet-->Spawn another object-->Explosion1, layer 1
<br/>Action: Bullet-->Destroy
<br/>**使Monster变得更聪明**:
<br/>Event: System-->On start of Layout
<br/>Action: Monster-->Set angle-->random(360)
<br/>**当Monster离开layout1时让他们指向Player**:
<br/>Event: Monster-->Is outside layout
<br/>Action: Monster-->Set angle toward position-->For X, Player.X - for Y, Player.Y.

3. 注意到Explosion2爆炸时有背景(黑色)，只需将Effects里的Blendmode从Normal改为Additive。
![](images\lab02\GIF7.gif)

## 六、实例变量
1. 我们要为Monster设置血量以不至于被一次消灭。
![](images\lab02\GIF81.gif)

2. 适当修改之前的Event以适应刚建立的实例变量Health。
<br/>比如Monster被Bullet击中一次后Health减1:
![](images\lab02\GIF9.gif)

3. 添加一个Event使得Monster的Health为0时死亡。
<br/>Event: Monster-->Compare instance variable-->Health, Less or equal, 0
<br/>Action: Monster-->Spawn another object-->Explosion1, layer 1
<br/>Action: Monster-->Destroy

4. 设置分数(Score)以及相关Event的修改。
![](images\lab02\GIF10.gif)

5. 展示分数。
![](images\lab02\GIF11.gif)

6. 使Monster可以不断产生。
<br/>Event: System-->Every X seconds-->3
<br/>Action: System-->Create object-->Monster, layer 1, 960 (for X), random(600) (for Y)

7. 使Monster可以杀死Palyer。
<br/>Event: Monster-->On collision with another object-->Player
<br/>Action: Player-->Destroy

## 至此，游戏的制作已经基本完成啦！

### 以下是游戏展示:
![](images\lab02\GIFXXXX.gif)
