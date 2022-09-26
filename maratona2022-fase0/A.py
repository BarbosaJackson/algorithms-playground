N = int(input())

while N > 0:
    name = input()
    notes = sorted([float(x) for x in input().split()])
    qnt_notes = len(notes)
    sum_notes = 0
    den = 1
    if qnt_notes == 1:
        sum_notes = notes[0]
        den = 2.0
    elif qnt_notes < 4:
        sum_notes = 0
        for n in notes:
            sum_notes += n
        den = qnt_notes
    else:
        den = 3.0
        sum_notes = 0
        for n in notes[1:]:
            sum_notes += n
    print(f'{name}: %.1f' % (sum_notes/den))
    N -= 1