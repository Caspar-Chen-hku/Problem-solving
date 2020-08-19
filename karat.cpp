/*
Students may decide to take different "tracks" or sequences of courses in the Computer Science curriculum. There may be more than one track that includes the same course, but each student follows a single linear track from a "root" node to a "leaf" node. In the graph below, their path always moves left to right.

Write a function that takes a list of (source, destination) pairs, and returns the name of all of the courses that the students could be taking when they are halfway through their track of courses.

Sample input:
all_courses = [
    ["Logic", "COBOL"],
    ["Data Structures", "Algorithms"],
    ["Creative Writing", "Data Structures"],
    ["Algorithms", "COBOL"],
    ["Intro to Computer Science", "Data Structures"],
    ["Logic", "Compilers"],
    ["Data Structures", "Logic"],
    ["Creative Writing", "System Administration"],
    ["Databases", "System Administration"],
    ["Creative Writing", "Databases"],
    ["Intro to Computer Science", "Graphics"],
]

Sample output (in any order):
          ["Data Structures", "Creative Writing", "Databases", "Intro to Computer Science"]

All paths through the curriculum (midpoint *highlighted*):

*Intro to C.S.* -> Graphics
Intro to C.S. -> *Data Structures* -> Algorithms -> COBOL
Intro to C.S. -> *Data Structures* -> Logic -> COBOL
Intro to C.S. -> *Data Structures* -> Logic -> Compiler
Creative Writing -> *Databases* -> System Administration
*Creative Writing* -> System Administration
Creative Writing -> *Data Structures* -> Algorithms -> COBOL
Creative Writing -> *Data Structures* -> Logic -> COBOL
Creative Writing -> *Data Structures* -> Logic -> Compilers

Visual representation:

                    ____________
                    |          |
                    | Graphics |
               ---->|__________|
               |                          ______________
____________   |                          |            |
|          |   |    ______________     -->| Algorithms |--\     _____________
| Intro to |   |    |            |    /   |____________|   \    |           |
| C.S.     |---+    | Data       |   /                      >-->| COBOL     |
|__________|    \   | Structures |--+     ______________   /    |___________|
                 >->|____________|   \    |            |  /
____________    /                     \-->| Logic      |-+      _____________
|          |   /    ______________        |____________|  \     |           |
| Creative |  /     |            |                         \--->| Compilers |
| Writing  |-+----->| Databases  |                              |___________|
|__________|  \     |____________|-\     _________________________
               \                    \    |                       |
                \--------------------+-->| System Administration |
                                         |_______________________|

Complexity analysis variables:

n: number of pairs in the input

*/

'use strict';

const prereqs_courses1 = [
  ['Data Structures', 'Algorithms'],
  ['Foundations of Computer Science', 'Operating Systems'],
  ['Computer Networks', 'Computer Architecture'],
  ['Algorithms', 'Foundations of Computer Science'],
  ['Computer Architecture', 'Data Structures'],
  ['Software Design', 'Computer Networks'],
];

const prereqs_courses2 = [
  ['Data Structures', 'Algorithms'],
  ['Algorithms', 'Foundations of Computer Science'],
  ['Foundations of Computer Science', 'Logic'],
];

const prereqs_courses3 = [['Data Structures', 'Algorithms']];

const allCourses = [
  ['Logic', 'COBOL'],
  ['Data Structures', 'Algorithms'],
  ['Creative Writing', 'Data Structures'],
  ['Algorithms', 'COBOL'],
  ['Intro to Computer Science', 'Data Structures'],
  ['Logic', 'Compilers'],
  ['Data Structures', 'Logic'],
  ['Creative Writing', 'System Administration'],
  ['Databases', 'System Administration'],
  ['Creative Writing', 'Databases'],
  ['Intro to Computer Science', 'Graphics'],
];

function findAllMidway(prereqs) {
  const graph = formGraph(prereqs);
  const paths = [];
  const backtracking = (path, curr) => {
    if (graph.get(curr).length === 0) {
      paths.push([...path]);
      return;
    }
    for (const next of graph.get(curr)) {
      backtracking(path, next);
    }
    path.pop(curr);
  };
  const firstCourses = findAllFirstCourses(prereqs);
  for (const course of firstCourses) {
    backtracking([], course);
  }
  const result = new Set();
  for (const path of paths) {
    if (path.length % 2 === 0) {
      result.add(path[path.length / 2 - 1]);
    } else {
      result.add(path[Math.floor(path.length / 2)]);
    }
  }
  return result;
}

function findAllFirstCourses(prereqs) {
  const result = [];
  const courses = new Set();
  const coursesHavePrereq = new Set();
  for (const prereq of prereqs) {
    courses.add(prereq[0]);
    courses.add(prereq[1]);
    coursesHavePrereq.add(prereq[1]);
  }
  for (const course of courses) {
    if (!coursesHavePrereq.has(course)) {
      result.push(course);
    }
  }
  return result;
}

function formGraph(prereqs) {
  const result = new Map();
  for (const prereq of prereqs) {
    if (result.has(prereq[0])) {
      result.get(prereq[0]).add(prereq[1]);
    } else {
      result.set(prereq[0], new Set([prereq[1]]));
    }
  }
  for (const prereq of prereqs) {
    if (!result.has(prereq[1])) {
      result.set(prereq[1], new Set());
    }
  }
  return result;
}

console.log(findAllMidway(allCourses));

function findMidway(prereqs) {
  const result = [];
  const coursesHavePrereq = new Set();
  for (const prereq of prereqs) {
    coursesHavePrereq.add(prereq[1]);
  }
  let curr;
  for (const prereq of prereqs) {
    if (!coursesHavePrereq.has(prereq[0])) {
      curr = prereq[0];
      break;
    }
  }
  const courses = [...coursesHavePrereq, curr];
  while (result.length !== courses.length) {
    result.push(curr);
    for (const prereq of prereqs) {
      if (curr === prereq[0]) {
        curr = prereq[1];
        break;
      }
    }
  }
  if (result.length % 2 === 0) {
    return result[result.length / 2 - 1];
  }
  return result[Math.floor(result.length / 2)];
}

const studentCoursePairs1 = [
  ['58', 'Linear Algebra'],
  ['94', 'Art History'],
  ['94', 'Operating Systems'],
  ['17', 'Software Design'],
  ['58', 'Mechanics'],
  ['58', 'Economics'],
  ['17', 'Linear Algebra'],
  ['17', 'Political Science'],
  ['94', 'Economics'],
  ['25', 'Economics'],
  ['58', 'Software Design'],
];

const studentCoursePairs2 = [
  ['42', 'Software Design'],
  ['0', 'Advanced Mechanics'],
  ['9', 'Art History'],
];

function findAllOverlaps(studentCoursePairs) {
  const map = new Map();
  for (const [studentId, course] of studentCoursePairs) {
    if (map.has(studentId)) {
      map.get(studentId).push(course);
    } else {
      map.set(studentId, [course]);
    }
  }
  const studentIds = [...map.keys()];
  const result = new Map();
  for (let i = 0; i < studentIds.length; i++) {
    for (let j = i + 1; j < studentIds.length; j++) {
      const key = `${studentIds[i]},${studentIds[j]}`;
      const overlaps = [];
      for (const course1 of map.get(studentIds[i])) {
        for (const course2 of map.get(studentIds[j])) {
          if (course1 === course2) {
            overlaps.push(course1);
          }
        }
      }
      result.set(key, overlaps);
    }
  }
  return result;
}

// console.log(findAllOverlaps(studentCoursePairs1));
// console.log(findAllOverlaps(studentCoursePairs2));