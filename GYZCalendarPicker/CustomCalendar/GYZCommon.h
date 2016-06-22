//
//  GYZCommon.h
//  GYZCalendarPicker
//
//  Created by Mac on 16/6/22.
//  Copyright © 2016年 GYZ. All rights reserved.
//

#ifndef GYZCommon_h
#define GYZCommon_h

#define PADDING 10
#define kLineHeight  1


#define IMAGE(img) [UIImage imageNamed:img]

/********颜色相关宏***********/
//十六进制颜色
#define UIColorFromRGB(rgbValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define kColor(R,G,B,A) [UIColor colorWithRed:R/255.f green:G/255.f blue:B/255.f alpha:A]

#define kScreenHeight [UIScreen mainScreen].bounds.size.height
#define kScreenWidth [UIScreen mainScreen].bounds.size.width


// View 坐标(x,y)和宽高(width,height)
#define X(v)               (v).frame.origin.x
#define Y(v)               (v).frame.origin.y
#define WIDTH(v)           (v).frame.size.width
#define HEIGHT(v)          (v).frame.size.height

#define MinX(v)            CGRectGetMinX((v).frame) // 获得控件屏幕的x坐标
#define MinY(v)            CGRectGetMinY((v).frame) // 获得控件屏幕的Y坐标

#define MidX(v)            CGRectGetMidX((v).frame) //横坐标加上到控件中点坐标
#define MidY(v)            CGRectGetMidY((v).frame) //纵坐标加上到控件中点坐标

#define MaxX(v)            CGRectGetMaxX((v).frame) //横坐标加上控件的宽度
#define MaxY(v)            CGRectGetMaxY((v).frame) //纵坐标加上控件的高度

//字体定义
#define k12Font [UIFont systemFontOfSize:12.0f]
#define k14Font [UIFont systemFontOfSize:14.0f]
#define k15Font [UIFont systemFontOfSize:15.0f]
#define k18Font [UIFont systemFontOfSize:18.0f]

#endif /* GYZCommon_h */
