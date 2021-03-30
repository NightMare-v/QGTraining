# QG训练营前端组第一周周记：
2021年3月30日

## 生活随记

###### 好肝，好累，附加真的辛苦呜呜呜

## 一周总结

#####  第一点，对于a标签的设置和伪类选择器hover之类的控制

##### 第二点，导航e栏一般li内再含标签a，作用一有防关键词堆砌而造成的嫌疑而导致搜索引擎降权的问题

```css
//a链接的 第一点 和 第二点
.head_nav ul li{
    float: left;
    margin: 0 15px;
    padding: 0 5px;
}
.head_nav ul li a{
    display: block;
    line-height: 52px;   
    font-size: 16px;
    color: black;
}
.head_nav ul li a:hover{
    color: #ed6f46;
    border-bottom: 2px solid #ed6f46;
```

``

##### 第三点，关于line-height控制行类的高度(居中)或狭义的定位

```css
.nav{
    float: left;
    margin-top: 44px;
    height: 52px;
    width: 280px;
    background-color: #ed6f46;
}
.nav>a{
    display: block;
    padding-left: 110px;
    line-height: 52px;   
    font-size: 18px;
    color: #fff;
```



对部分`li`的标签进行了修改，添加了a链接 `display: block;` 的运用，将其转化为块状元素可以使其在整个`div`都能进行链接的点击.

## 存在问题

###### 目前已经是学到了css定位了，我曾经认为我都懂了。结果是，确实，只是用就不知道怎么用，当我尝试开始写页面的时候，这样快速学习的缺点就稍微暴露出来了，在打代码的时候下手不太清楚应该用哪些标签和属性，因为学过的东西太多了，不知道如何选。然而，我认为既然是这样的学习方法，那么就更应该多点锻炼了

## 下周规划

###### 接着肝
