//
//  ISSViewPrototype.h
//  Part of InterfaCSS - http://www.github.com/tolo/InterfaCSS
//
//  Copyright (c) Tobias Löfstrand, Leafnode AB.
//  License: MIT (http://www.github.com/tolo/InterfaCSS/LICENSE)
//

#import <Foundation/Foundation.h>


typedef UIView* (^ViewBuilderBlock)(UIView* superview);

/**
 * Represents a registered view prototype.
 */
@interface ISSViewPrototype : NSObject

@property (nonatomic, strong, readonly) NSString* name;

@property (nonatomic, strong, readonly) NSString* propertyName;
@property (nonatomic) BOOL implicitPropertyName;
@property (nonatomic, readonly) BOOL addAsSubView;

@property (nonatomic, copy, readonly) ViewBuilderBlock viewBuilderBlock;
@property (nonatomic, strong) NSArray* subviewPrototypes;

@property (nonatomic) BOOL prototypeScopeParent;

+ (instancetype) prototypeWithName:(NSString*)name propertyName:(NSString*)propertyName addAsSubView:(BOOL)addAsSubView viewBuilderBlock:(ViewBuilderBlock)viewBuilderBlock;

- (UIView*) createViewObjectFromPrototypeWithParent:(id)parentObject;

@end
