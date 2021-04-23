#!/usr/bin/perl

# Alanté "Alan" D. Powell
# Spring 20201 - Programming Language Concepts
# Exam 2 - Question 3 - Q3_Perl.pl
# References YouTube

# Hashes
%classmates_and_age = (
         "Alan" => 24,
         "John" => 48,
         "Alex" => 18,
         "Rebecca" => 32,
         "Joshua" => 29,
         "Alicia" => 22,
         "Austin" => 49,
         "Rory" => 23
         );

# Operation 1 -> Get a specific value from the hash
print "Alicia is $classmates_and_age{'Alicia'} years old. \n";
print "Alan is $classmates_and_age{'Alan'} years old. \n";
print "Rory is $classmates_and_age{'Rory'} years old. \n";
print "John is $classmates_and_age{'John'} years old. \n";
print "Joshua is $classmates_and_age{'Joshua'} years old. \n";
print "Austin is $classmates_and_age{'Austin'} years old. \n";

# Operation 2 -> Get the number of keys in the hash
@keys = keys %classmates_and_age;
$size = @keys;
print "There are $size students in this class.";

# Operation 3 -> Remove items from the hash
print "The current number of students in the class is $size.";
print "Alex is no longer in this class.";
print "Alan graduated.";
delete $classmates_and_age{'Alex'};
delete $classmates_and_age{'Alan'};
@keys = keys %classmates_and_age;
$size = @keys;
print "The class now has $size students.";

# Operation 4 -> Add a student to the class
$classmates_and_age{'Aaron'} = 20;
@keys = keys %classmates_and_age;
$size = @keys;
print "With Aaron in the class, we now have $size students.";

# Arrays
@classmates_names = ('Alan', 'John', 'Alex', 'Rebecca', 'Joshua', 'Alicia', 'Austin', 'Rory');
@classmates_ages = (24, 48, 18, 32, 29, 22, 49, 23);

# Operation 1 -> Get a specific value from the hash
@index = index($classmates_names, 'Alicia');
@value_at_index = $classmates_ages[$index];
print "Alicia is $value_at_index years old.";

@index = index($classmates_names, 'John');
@value_at_index = $classmates_ages[$index];
print "John is $value_at_index years old.";

@index = index($classmates_names, 'Alan');
@value_at_index = $classmates_ages[$index];
print "Alan is $value_at_index years old.";

# Operation 2 -> Get the number of elements in the array
$size = @classmates_names;
print "There are $size students in the class.";

# Operation 3 -> Remove items from the array
print "Rory graduated.";
pop(@classmates_names);
pop(@classmates_ages);
$size = @classmates_names;
print "There are now $size students in the class.";

# Operation 4 -> Add a student to the class
print "We got a new student named Tanner!";
push(@classmates_names, 'Tanner');
push(@classmates_ages, 24);
$size = @classmates_names;
print "With Tanner, we now have @size students in the class!";
