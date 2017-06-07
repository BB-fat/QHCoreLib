//
//  NSObject+QHUserDefaultsProperty.h
//  QHCoreLib
//
//  Created by changtang on 2017/6/7.
//  Copyright © 2017年 Tencent. All rights reserved.
//


#import <Foundation/Foundation.h>


@interface NSObject (QHStandardUserDefaultsProperty)

+ (void)qh_synthesizeBOOLProperty:(NSString *)propertyName
                           forKey:(NSString *)userDefaultsKey
                     defaultValue:(BOOL)defaultValue
                     userDefaults:(NSUserDefaults *)userDefaults;

+ (void)qh_synthesizeIntegerProperty:(NSString *)propertyName
                              forKey:(NSString *)userDefaultsKey
                        defaultValue:(NSInteger)defaultValue
                        userDefaults:(NSUserDefaults *)userDefaults;

+ (void)qh_synthesizeDoubleProperty:(NSString *)propertyName
                             forKey:(NSString *)userDefaultsKey
                       defaultValue:(double)defaultValue
                       userDefaults:(NSUserDefaults *)userDefaults;

+ (void)qh_synthesizeStringProperty:(NSString *)propertyName
                             forKey:(NSString *)userDefaultsKey
                       defaultValue:(NSString *)defaultValue
                       userDefaults:(NSUserDefaults *)userDefaults;

+ (void)qh_synthesizeArrayProperty:(NSString *)propertyName
                            forKey:(NSString *)userDefaultsKey
                      defaultValue:(NSArray *)defaultValue
                      userDefaults:(NSUserDefaults *)userDefaults;

+ (void)qh_synthesizeDictionaryProperty:(NSString *)propertyName
                                 forKey:(NSString *)userDefaultsKey
                           defaultValue:(NSDictionary *)defaultValue
                           userDefaults:(NSUserDefaults *)userDefaults;


// synthesize in standardUserDefaults

+ (void)qh_synthesizeBOOLProperty:(NSString *)propertyName
                           forKey:(NSString *)userDefaultsKey
                     defaultValue:(BOOL)defaultValue;

+ (void)qh_synthesizeIntegerProperty:(NSString *)propertyName
                              forKey:(NSString *)userDefaultsKey
                        defaultValue:(NSInteger)defaultValue;

+ (void)qh_synthesizeDoubleProperty:(NSString *)propertyName
                             forKey:(NSString *)userDefaultsKey
                       defaultValue:(double)defaultValue;

+ (void)qh_synthesizeStringProperty:(NSString *)propertyName
                             forKey:(NSString *)userDefaultsKey
                       defaultValue:(NSString *)defaultValue;

+ (void)qh_synthesizeArrayProperty:(NSString *)propertyName
                            forKey:(NSString *)userDefaultsKey
                      defaultValue:(NSArray *)defaultValue;

+ (void)qh_synthesizeDictionaryProperty:(NSString *)propertyName
                                 forKey:(NSString *)userDefaultsKey
                           defaultValue:(NSDictionary *)defaultValue;

@end