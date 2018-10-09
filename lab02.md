# 用Construct 2制作一款简单的html游戏
>很多人都喜欢玩游戏,可是说到制作游戏,绝大多数人就开始挠头了,今天博主就向大家展示如何制作一款简单的html游戏。


## 一、下载并安装Construct 2
[点击这里](http：//www.scirra.com/construct2/releases/new)以下载最新版本的Construct 2
<br/>进入网页后点击Download即可下载
![](https://thumbnail0.baidupcs.com/thumbnail/5207c2218f8d6d6d7d2c75e092cdb79c?fid=1262615369-250528-835106058451308&time=1539079200&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-xIEkrUNWQP9jM4MZZPd%2BmLnV55g%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6534797792351965071&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)
## 二、新建一个项目
安装好Construct 2之后,进入程序,新建项目即可
![](https://thumbnail0.baidupcs.com/thumbnail/dd8341b48c3a3612744b645230c60f19?fid=1262615369-250528-788405599058699&time=1539079200&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-dcOwHM%2BLhDjRh4mZkvor7zYJj0k%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6534806656881660716&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

## 三、插入对象(背景、人物、效果等)
1. 首先应该寻找一张作为背景的图片博主选择的是大雄(哆啦A梦中人物)背景，如下图所示:
![](https://thumbnail0.baidupcs.com/thumbnail/2b7a94180a641c78a2aa562fa2072777?fid=1262615369-250528-525615566557522&time=1539079200&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-urcB4zlvsHIL%2FleXAzD14SEtGdc%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6534824071088373757&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

2. 双击空白以插入对象,点击Tiled Background,点击insert以插入,出现十字准线后单击,会打开Edit texture,点击load an image from a file,找到背景图的位置,然后选择它,关闭Edit texture,调整背景以及布局(白色区域)的大小使其几乎重叠
![](https://thumbnail0.baidupcs.com/thumbnail/9013cd39606af58731138eb42a37e198?fid=1262615369-250528-721059808381622&time=1539079200&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-s0Auo7UyVh77GNw6H05N45G9Es4%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6534831441313539801&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

3. 添加图层Main,确保在图层栏中选择了“Main”图层。这很重要因为所选图层是活动图层。所有新插入的对象都插入到活动层中,因此如果未选中,我们将意外插入到错误的层。
![](https://thumbnail0.baidupcs.com/thumbnail/867a84adf199015defc200252a52990d?fid=1262615369-250528-32386751190980&time=1539079200&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-4LVDwTTpEV6Uchqt5Rx%2BKluX1a8%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6534847209103569630&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

4. 添加输入对象,双击layout1空白处以插入另外的新对象,这次是Mouse和Keyboard。这些对象不需要放置在布局中。它们是隐藏的,并自动在项目范围内工作。现在我们项目中的所有布局都可以接受鼠标和键盘输入。
5. 插入游戏对象，比如**Player**(哆啦A梦)、**Monster**(老鼠，因为哆啦A梦的耳朵被老鼠咬掉了)、**Bullet**(哆啦A梦最喜欢的铜锣烧)、**Explosion**(爆炸效果)等。
![](https://thumbnail0.baidupcs.com/thumbnail/a96e25f5f6426b053327b2afcca4a157?fid=1262615369-250528-568192185873578&time=1539061200&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-yq%2FtDMgBJXgIM%2BhmhUw16M8vpfI%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6530018395443267814&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

## 四、添加行为
1. 了解一些行为:
<br/>8 Direction movement:这使您可以使用箭头键移动对象。它会很好地适应玩家的运动。
<br/>Bullet movement:这只是以当前角度向前移动一个物体。它对玩家的子弹很有用。尽管有这个名字,它也可以很好地移动怪物,因为所有的移动都是以某种速度向前移动物体。
<br/>Scroll to:这使得屏幕在移动时跟随对象,这对玩家有用。
<br/>Bound to layout:这将停止一个物体离开布局区域。这对玩家也很有用,所以他们不能在游戏区域外游荡！
<br/>Destroy outside layout:而不是停止离开布局区域的对象,如果它停止,则会破坏它。它对我们的子弹很有用。没有它,子弹将永远飞离屏幕,总是占用一点内存和处理能力。相反,我们应该在他们离开布局后销毁子弹。
<br/>Fade:这逐渐使物体淡出,我们将用于爆炸。
2. 如何添加行为:
![](https://thumbnail0.baidupcs.com/thumbnail/6adeb41f573f4fdcb49001caf9e72594?fid=1262615369-250528-958467790108203&time=1539061200&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-soR%2FMrwP3%2FqhjwUMHwURX7Ow8K8%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6530404537147715726&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

3. 创建更多的Monster。按住Ctrl用鼠标拖动Monster以创建,七至八个即可。
![](https://thumbnail0.baidupcs.com/thumbnail/0c52a2c615a6b7fc0234af93b98d7b7f?fid=1262615369-250528-665611914807637&time=1539072000&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-se4Whks%2B2sUeFL7z6%2FQjLWMheMk%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6533207857246463992&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

## 五、添加活动(Event)
1. 要想让Player一直看着鼠标,完成起来应该会这样。
![](https://thumbnail0.baidupcs.com/thumbnail/9f1b49be013ba371722b2d1efa2cdcd1?fid=1262615369-250528-355900549464614&time=1539072000&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-FjGvT9hHYE%2F6MJkcp0u%2BuYurjV8%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6533331202239012594&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

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
![](https://thumbnail0.baidupcs.com/thumbnail/2b2cbb4d3f917266909fbd0cc983f12b?fid=1262615369-250528-228063606848293&time=1539072000&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-3botuVOxA6OIbk2pgeK5UI55khM%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6533465803544638850&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

## 六、实例变量
1. 我们要为Monster设置血量以不至于被一次消灭。
![](https://thumbnail0.baidupcs.com/thumbnail/bac545b9319c7598e78135817bb47588?fid=1262615369-250528-924624479338601&time=1539075600&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-sfGpg6Rf2D7klvXkQDqdt%2Bka8UA%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6533846000724371230&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

2. 适当修改之前的Event以适应刚建立的实例变量Health。
<br/>比如Monster被Bullet击中一次后Health减1:
![](https://thumbnail0.baidupcs.com/thumbnail/50d1e42072a6f066e5d58db5aeb10980?fid=1262615369-250528-624210506975890&time=1539075600&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-fVTQDcgz3jZYkbGczGg8qZB9b7w%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6533984221145251885&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

3. 添加一个Event使得Monster的Health为0时死亡。
<br/>Event: Monster-->Compare instance variable-->Health, Less or equal, 0
<br/>Action: Monster-->Spawn another object-->Explosion1, layer 1
<br/>Action: Monster-->Destroy

4. 设置分数(Score)以及相关Event的修改。
![](https://thumbnail0.baidupcs.com/thumbnail/ccb9fae2a1b073598a1297c7ca5927c2?fid=1262615369-250528-734402643319316&time=1539075600&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-5G9uS%2Fw%2F2gpusnlJULwlY4kFERw%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6534094368003094590&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

5. 展示分数。
![](https://thumbnail0.baidupcs.com/thumbnail/bb1e1e83890e199f6f882f3c5475854e?fid=1262615369-250528-886601065635455&time=1539075600&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-fk%2Fo%2Bb1xoQAVGQuaoFgoTgJ7VUE%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6534256652247125008&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)

6. 使Monster可以不断产生。
<br/>Event: System-->Every X seconds-->3
<br/>Action: System-->Create object-->Monster, layer 1, 960 (for X), random(600) (for Y)

7. 使Monster可以杀死Palyer。
<br/>Event: Monster-->On collision with another object-->Player
<br/>Action: Player-->Destroy

## 至此，游戏的制作已经基本完成啦！

### 以下是游戏展示:
![](https://thumbnail0.baidupcs.com/thumbnail/f010299b83b62109a422fb8e68f6ca70?fid=1262615369-250528-616955808193613&time=1539079200&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-txkNjLDFJ4AuQvJpy4wWjKZioAI%3D&expires=8h&chkv=0&chkbd=0&chkpc=&dp-logid=6534679920980002688&dp-callid=0&size=c710_u400&quality=100&vuk=-&ft=video)
