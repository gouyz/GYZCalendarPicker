//
//  GYZCustomCalendarPickerView.h
//  GYZCalendarPicker
//
//  Created by GYZ on 16/6/22.
//  Copyright © 2016年 GYZ. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDJChineseCalendar.h"
#import "IDJCalendarUtil.h"
#import "GYZCommon.h"

#define YEAR_START 1970//滚轮显示的起始年份
#define YEAR_END 2049//滚轮显示的结束年份


//日历显示的类型
typedef NS_ENUM(NSUInteger, CalendarType) {
    GregorianCalendar=1,//公历、阳历
    ChineseCalendar  //农历、阴历
};

@protocol GYZCustomCalendarPickerViewDelegate;

@interface GYZCustomCalendarPickerView : UIView<UIPickerViewDelegate,UIPickerViewDataSource>

@property(nonatomic) CalendarType calendarType;
@property (nonatomic, assign) id<GYZCustomCalendarPickerViewDelegate> delegate;

- (instancetype)initWithTitle:(NSString *)title;
-(void)show;
@end

@protocol GYZCustomCalendarPickerViewDelegate <NSObject>
//通知使用这个控件的类，用户选取的日期
- (void)notifyNewCalendar:(IDJCalendar *)cal;
@end