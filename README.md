## README.md

### 0. 版本更新

>  `v1.0.0   2022.11.18-19:47`
>
>  `v1.1.0   2022.11.19-20:56`
>
>  `v1.1.1   2022.12.05-15:20`



### 1. 玩法与目标

>  #### 1.1. 玩法
>
> > 将两个元素合成，获取新元素（见 `2.3. 元素的合成`）
> >
> > **PS：为了方便，使用全英文界面**
>
> #### 1.2. 目标
>
> >  获得所有终极元素



### 2. 元素

> #### 2.1. 初级元素
>
> > 金，木，水，火，土
>
> #### 2.2. 终级元素
>
> > 金子，泥，空气，海滩，地图，水星，火星，土星，木星，金星，地球
>
> #### 2.3. 元素的合成
>
> > ```
> > 水 + 木 = 树
> > 金 + 火 = 金子
> > 水 + 土 = 泥
> > 火 + 土 = 灰尘
> > 火 + 木 = 灰尘
> > 水 + 火 = 空气
> > 树 + 树 = 森林
> > 森林 + 火 = 灰尘
> > 灰尘 + 土 = 沙漠
> > 沙漠 + 海 = 海滩
> > 灰尘 + 水 = 纸
> > 纸 + 城市 = 地图
> > 纸 + 国家 = 地图
> > 纸 + 陆地 = 地图
> > 纸 + 地球 = 地图
> > 纸 + 纸 = 书
> > 纸 + 火 = 灰尘
> > 书 + 火 = 灰尘
> > 火 + 金 = 太阳
> > 太阳 + 水 = 星球
> > 星球 + 水 = 水星
> > 星球 + 火 = 火星
> > 星球 + 土 = 土星
> > 星球 + 木 = 木星
> > 星球 + 金 = 金星
> > 水 + 水 = 湖
> > 湖 + 湖 = 海
> > 海 + 海 = 洋
> > 土 + 土 = 城市
> > 城市 + 城市 = 国家
> > 国家 + 国家 = 陆地
> > 陆地 + 洋 = 地球
> > ```



### 3. 操作说明

> |  操作名称  |     功能     |          参数          |         备注         |
> | :--------: | :----------: | :--------------------: | :------------------: |
> |  $print$   | 输出现有元素 |           -            |          -           |
> |   $save$   |     存档     |           -            |          -           |
> |   $add$    | 添加元素 |  ($password$ - 密码)  |          -           |
> |  $merge$   | 合成元素 | $item1/2$ - 元素 $1/2$ |          -           |
> | $settings$ |     设置     |     $type$ - 类型     |    -     |
> | $settings$ $-npsw$ |     设置新密码     |   ($password$ - 密码)， $new$ $password$ - 新密码   | - |
> | $settings$ $-cpsw$ |     关闭密码     |   ($password$ - 密码)   | - |
> |  $clear$   |     清屏     |           -            |          -           |
> |   $help$   |     帮助     |           -            |          -           |
> |  $break$   |     退出     |           -            |       自动存档       |