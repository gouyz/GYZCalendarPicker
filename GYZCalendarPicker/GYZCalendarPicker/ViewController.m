//
//  ViewController.m
//  GYZCalendarPicker
//
//  Created by Mac on 16/6/22.
//  Copyright © 2016年 GYZ. All rights reserved.
//

#import "ViewController.h"
#import "GYZCustomCalendarPickerView.h"
#import "IDJCalendarUtil.h"

@interface ViewController ()<GYZCustomCalendarPickerViewDelegate>{
    UIButton *_selectBtn;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _selectBtn = [[UIButton alloc]initWithFrame:CGRectMake(30, 100, WIDTH(self.view)-30*2, 60)];
    [_selectBtn setTitle:@"点击" forState:UIControlStateNormal];
    [_selectBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [_selectBtn addTarget:self action:@selector(showCalendar) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_selectBtn];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)showCalendar{
    //日期实现
    GYZCustomCalendarPickerView *pickerView = [[GYZCustomCalendarPickerView alloc]initWithTitle:@"选择日期"];
    pickerView.delegate = self;
    pickerView.calendarType = GregorianCalendar;//日期类型
    [pickerView show];
}

#pragma QTCustomCalendarPickerViewDelegate
//接收日期选择器选项变化的通知
- (void)notifyNewCalendar:(IDJCalendar *)cal {
    NSString *result = @"点击";
    if ([cal isMemberOfClass:[IDJCalendar class]]) {//阳历
    
        NSString *year =[NSString stringWithFormat:@"%@",cal.year];
        NSString *month = [cal.month intValue] > 9 ? cal.month:[NSString stringWithFormat:@"0%@",cal.month];
        NSString *day = [cal.day intValue] > 9 ? cal.day:[NSString stringWithFormat:@"0%@",cal.day];
        result = [NSString stringWithFormat:@"%@-%@-%@",year,month, day];
        
    } else if ([cal isMemberOfClass:[IDJChineseCalendar class]]) {//阴历
        
        IDJChineseCalendar *_cal=(IDJChineseCalendar *)cal;
        
        NSArray *array=[_cal.month componentsSeparatedByString:@"-"];
        NSString *dateStr = @"";
        if ([[array objectAtIndex:0]isEqualToString:@"a"]) {
            dateStr = [NSString stringWithFormat:@"%@%@",dateStr,[_cal.chineseMonths objectAtIndex:[[array objectAtIndex:1]intValue]-1]];
        } else {
            dateStr = [NSString stringWithFormat:@"%@闰%@",dateStr,[_cal.chineseMonths objectAtIndex:[[array objectAtIndex:1]intValue]-1]];
        }
        result = [NSString stringWithFormat:@"%@%@",dateStr, [NSString stringWithFormat:@"%@", [_cal.chineseDays objectAtIndex:[_cal.day intValue]-1]]];
    }
    [_selectBtn setTitle:result forState:UIControlStateNormal];
    
}
@end
