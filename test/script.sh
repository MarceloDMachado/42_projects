#!/bin/bash

FILES=$(git diff main | grep "diff --git")

echo $FILES
