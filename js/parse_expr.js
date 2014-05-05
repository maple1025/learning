/*
 * Parse a expression.
 * http://eloquentjavascript.net/2nd_edition/preview/11_language.html
 */

/* jshint node: true */
/* jshint -W084 */

"use strict";

function parseExpression(program) {
    program = skipSpace(program);
    var match, expr;
    if (match = /^"([^"]*)"/.exec(program)) {
        expr = {
            type: "value",
            value: match[1]
        };
    } else if (match = /^\d+\b/.exec(program)) {
        expr = {
            type: "value",
            value: Number(match[0])
        };
    } else if (match = /^[^\s(),"]+/.exec(program)) {
        expr = {
            type: "word",
            name: match[0],
        };
    } else
        throw new SyntaxError("Unexpected syntax: " + program);

    return parseApply(expr, program.slice(match[0].length));
}

function skipSpace(string) {
    var first = string.search(/\S/);
    if (first == -1) return "";
    return string.slice(first);
}

function parseApply(left, program) {
    program = skipSpace(program);
    if (program[0] != "(")
        return {expr: left, rest: program};

    program = skipSpace(program.slice(1));
    var expr = {
        type: "apply",
        operator: left,
        args: []
    };
    while (program[0] != ")") {
        var arg = parseExpression(program);
        expr.args.push(arg.expr);
        program = skipSpace(arg.rest);
        if (program[0] == ",")
            program = skipSpace(program.slice(1));
        else if (program[0] != ")")
            throw new SyntaxError("Expected ',' or ')'");
    }

    return parseApply(expr, program.slice(1));
}
