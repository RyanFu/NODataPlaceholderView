//
//  UIScrollView+NoDataExtend.h
//  NODataPlaceholderView
//
//  Created by Ossey on 2017/5/29.
//  Copyright © 2017年 Ossey. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NoDataPlaceholderDelegate;

@interface UIScrollView (NoDataExtend)

@property (nonatomic, weak, nullable) id<NoDataPlaceholderDelegate> noDataPlaceholderDelegate;

/// 获取子控件
@property (nonatomic, copy) UIView * _Nullable (^customNoDataView)(void);
@property (nonatomic, copy) UILabel * _Nullable(^noDataTextLabel)(void);
@property (nonatomic, copy) UILabel * _Nullable(^noDataDetailTextLabel)(void);
@property (nonatomic, copy) UIImageView * _Nullable(^noDataImageView)(void);
@property (nonatomic, copy) UIButton * _Nullable(^noDataReloadButton)(void);

// 使用默认的子控件 
@property (nonatomic, copy) void  (^ _Nullable noDataTextLabelBlock)(UILabel *textLabel);
@property (nonatomic, copy) void  (^ _Nullable noDataDetailTextLabelBlock)(UILabel *detailTextLabel);
@property (nonatomic, copy) void  (^ _Nullable noDataImageViewBlock)(UIImageView *imageView);
@property (nonatomic, copy) void  (^ _Nullable noDataReloadButtonBlock)(UIButton *reloadButton);

@property (nonatomic, assign) UIEdgeInsets noDataTextEdgeInsets;
@property (nonatomic, assign) UIEdgeInsets noDataImageEdgeInsets;
@property (nonatomic, assign) UIEdgeInsets noDataDetailEdgeInsets;
@property (nonatomic, assign) UIEdgeInsets noDataButtonEdgeInsets;

@property (nonatomic, strong) UIColor *noDataViewBackgroundColor;
@property (nonatomic, assign) BOOL xy_loading;

- (void)reloadNoDataView;

@end

@protocol NoDataPlaceholderDelegate <NSObject>

@optional

/// 是否应该淡入淡出，默认为YES
- (BOOL)noDataPlaceholderShouldFadeInOnDisplay:(UIScrollView *)scrollView;

/// 是否应显示NoDataPlaceholderView, 默认YES
/// @return 如果当前无数据则应显示NoDataPlaceholderView
- (BOOL)noDataPlaceholderShouldDisplay:(UIScrollView *)scrollView;

/// 当前所在页面的数据源itemCount>0时，是否应该实现NoDataPlaceholder，默认是不显示的
/// @return 如果需要强制显示NoDataPlaceholder，return YES即可
- (BOOL)noDataPlaceholderShouldBeForcedToDisplay:(UIScrollView *)scrollView;

/// 当noDataPlaceholder即将显示的回调
- (void)noDataPlaceholderWillAppear:(UIScrollView *)scrollView;

/// 当noDataPlaceholder完全显示的回调
- (void)noDataPlaceholderDidAppear:(UIScrollView *)scrollView;

/// 当noDataPlaceholder即将消失的回调
- (void)noDataPlaceholderWillDisappear:(UIScrollView *)scrollView;

/// 当noDataPlaceholder完全消失的回调
- (void)noDataPlaceholderDidDisappear:(UIScrollView *)scrollView;

/// noDataPlaceholder是否可以响应事件，默认YES
- (BOOL)noDataPlaceholderShouldAllowResponseEvent:(UIScrollView *)scrollView;

/// noDataPlaceholder是否可以滚动，默认NO
- (BOOL)noDataPlaceholderShouldAllowScroll:(UIScrollView *)scrollView;

- (void)noDataPlaceholder:(UIScrollView *)scrollView didTapOnContentView:(UITapGestureRecognizer *)tap;

- (void)noDataPlaceholder:(UIScrollView *)scrollView didClickReloadButton:(UIButton *)button;

/// NoDataPlaceholderView各子控件之间垂直的间距，默认为11
- (CGFloat)contentSubviewsGlobalVerticalSpaceFoNoDataPlaceholder:(UIScrollView *)scrollView;

/// NoDataPlaceholderView contenView 中心点y 轴 距离 父控件scrollView 中心点y 的偏移量
/// 默认为0，与所在scrollView的中心点显示
- (CGFloat)contentOffsetYForNoDataPlaceholder:(UIScrollView *)scrollView;

@end


NS_ASSUME_NONNULL_END