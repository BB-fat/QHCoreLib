//
//  QHCoreLibFoundationTests.m
//  QHCoreLib
//
//  Created by changtang on 2017/5/25.
//  Copyright © 2017年 Tencent. All rights reserved.
//

#import <XCTest/XCTest.h>

#import "Foundation+QHCoreLib.h"


@interface QHCoreLibFoundationTests : XCTestCase

@end

@implementation QHCoreLibFoundationTests

- (void)testNSArray
{
    NSArray *array = @[ @1, @2, @3 ];

    XCTAssertEqualObjects([array qh_sliceFromStart:1 length:2],
                          [array subarrayWithRange:NSMakeRange(1, 2)]);

    XCTAssertEqualObjects([array qh_sliceFromStart:1 length:3],
                          [array subarrayWithRange:NSMakeRange(1, 2)]);

    XCTAssertEqualObjects([array qh_sliceFromStart:3 length:1],
                          @[]);

    XCTAssertEqualObjects([array qh_filteredArrayWithBlock:^BOOL(NSUInteger idx, id obj) {
        return ((idx + 1) % 2) == 0;
    }], @[ @2 ]);

    NSArray *reverseArray = @[ @3, @2, @1 ];
    XCTAssertEqualObjects([array qh_mappedArrayWithBlock:^id(NSUInteger idx, id obj) {
        return @(4 - [obj integerValue]);
    }], reverseArray);

    XCTAssertEqualObjects([array qh_objectAtIndex:0], @1);
    XCTAssertEqualObjects([array qh_objectAtIndex:3], nil);

    XCTAssertEqualObjects([array qh_objectsAtIndexes:[NSIndexSet indexSetWithIndex:0]],
                          @[ @1 ]);
    XCTAssertEqualObjects([array qh_objectsAtIndexes:[NSIndexSet indexSetWithIndex:3]],
                          @[ ]);
}

- (void)testArrayDefaultValue
{
    NSArray *array = @[ [NSObject new], @YES, @1, @1.0, @"1", @[ @1 ], @{ @1: @1 } ];

    XCTAssertEqual([array qh_boolAtIndex:0], NO);
    XCTAssertEqual([array qh_boolAtIndex:1], YES);

    XCTAssertEqual([array qh_integerAtIndex:0], 0);
    XCTAssertEqual([array qh_integerAtIndex:2], 1);

    XCTAssertEqual([array qh_doubleAtIndex:0], 0.0);
    XCTAssertEqual([array qh_doubleAtIndex:3], 1.0);

    XCTAssertEqualObjects([array qh_stringAtIndex:0], @"");
    XCTAssertEqualObjects([array qh_stringAtIndex:4], @"1");

    XCTAssertEqualObjects([array qh_arrayAtIndex:0], @[]);
    XCTAssertEqualObjects([array qh_arrayAtIndex:5], @[ @1 ]);

    XCTAssertEqualObjects([array qh_dictionaryAtIndex:0], @{});
    XCTAssertEqualObjects([array qh_dictionaryAtIndex:6], @{ @1: @1 });
}

- (void)testNSMutableArray
{
    NSMutableArray *array = [NSMutableArray array];

    [array qh_addObject:nil];
    [array qh_addObject:@1];

    [array qh_insertObject:nil atIndex:array.count];
    [array qh_insertObject:@1 atIndex:array.count];
    [array qh_insertObject:@1 atIndex:array.count + 1];

    [array qh_removeObjectAtIndex:array.count];
    [array qh_removeObjectAtIndex:0];
}

- (void)testNSDictionary
{
    NSDictionary *dict = @{ @1: @1, @2: @2 };
    NSDictionary *result = @{ @1: @2, @2: @4 };

    XCTAssertEqualObjects([dict qh_mappedDictionaryWithBlock:^id(id key, id obj) {
        return @([obj integerValue] * 2);
    }], result);
}

- (void)testNSDictionaryDefaultValue
{
    NSDictionary *dict = @{ @0: [NSObject new],
                            @1: @YES,
                            @2: @1,
                            @3: @1.0,
                            @4: @"1",
                            @5: @[ @1 ],
                            @6: @{ @1: @1 } };
    XCTAssertEqual([dict qh_boolForKey:@0], NO);
    XCTAssertEqual([dict qh_boolForKey:@1], YES);

    XCTAssertEqual([dict qh_integerForKey:@0], 0);
    XCTAssertEqual([dict qh_integerForKey:@2], 1);

    XCTAssertEqual([dict qh_doubleForKey:@0], 0.0);
    XCTAssertEqual([dict qh_doubleForKey:@3], 1.0);

    XCTAssertEqualObjects([dict qh_stringForKey:@0], @"");
    XCTAssertEqualObjects([dict qh_stringForKey:@4], @"1");

    XCTAssertEqualObjects([dict qh_arrayForKey:@0], @[]);
    XCTAssertEqualObjects([dict qh_arrayForKey:@5], @[ @1 ]);

    XCTAssertEqualObjects([dict qh_dictionaryForKey:@0], @{});
    XCTAssertEqualObjects([dict qh_dictionaryForKey:@6], @{ @1: @1 });
}

- (void)testNSMutableDictionary
{
    NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithDictionary:@{ @1: @1, @2: @2 }];

    [dict qh_setObject:nil forKey:nil];
    [dict qh_setObject:nil forKey:@1];
    [dict qh_setObject:@1 forKey:nil];
    [dict qh_setObject:@2 forKey:@1];
    XCTAssertEqualObjects(@2, dict[@1]);
}

@end