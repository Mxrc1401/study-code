# Lab 1 – Section I: Software Development Process Models

## 1. Software Development Life Cycle

### Assignment to SDLC phases

| Activity | SDLC phase |
|----------|------------|
| A. Implement connection search algorithm | 4. Implementation |
| B. Students test if app meets expectations | 5. Testing & Integration (acceptance test) |
| C. Determine what functionality students need | 1. Planning / 2. Analysis |
| D. Release to the university app store | 5. Testing & Integration → transition to 6. Maintenance (deployment) |
| E. Define components and interfaces | 3. Design |
| F. Fix defects and adapt after release | 6. Maintenance |
| G. Check if app fulfills specified requirements | 5. Testing & Integration (system test) |

### Order

**C → E → A → G → B → D → F**

### Typical artifacts

| Activity | Artifact |
|----------|----------|
| Requirements Engineering | Requirements specification (e.g. user stories / use cases) |
| Design | Architecture diagram (components and interfaces, e.g. UML) |
| Implementation | Source code (incl. unit tests) |
| Testing | Test plan / test report |

---

## 2. Waterfall Model

### Simplified Waterfall Model

```text
Requirements            (C)
   └─► Design           (E)
         └─► Development       (A)
               └─► Testing           (G, B)
                     └─► Deploying         (D)
                           └─► Maintenance       (F)
```

Linear and sequential: the next phase only starts when the previous one is completed. There is no backtracking.

### Why it can work with stable requirements

If the requirements are clear and don't change, the whole project can be planned up front. Each phase delivers a finished result that the next phase builds on. This makes the project easy to plan and control. A campus app is a small to medium-sized project, which suits the Waterfall Model.

### Problem: late request for public transport integration

The Waterfall Model omits backtracking. Requirements and design are already completed, so larger changes aren't planned for. The new feature needs new requirements, a new interface to an external provider in the design, and changes to existing code. Going back to earlier phases is expensive and delays the project. Because testing comes late and as an isolated step, problems caused by the change are also found late.

### Advantages / Disadvantages

| Advantages | Disadvantages |
|------------|---------------|
| Clearly structured, easy to plan and manage | No backtracking, so it's inflexible when requirements change |
| Every phase has a clear, documented result | Testing happens late and in an isolated step, so errors are found late |

---

## 3. V-Model

### Simplified V-Model

```text
Requirements Specification ◄──────────────────────► Acceptance Testing
      System Design ◄─────────────────────────► System Testing
            Software / Component Design ◄──► Integration Testing
                          \                  /
                           \                /
                            Implementation ◄──► Unit Testing
```

(Left side: development, bottom: coding, right side: testing)

### Assignment of test levels

| Development activity | Test level | Checks... |
|----------------------|------------|-----------|
| Requirements Specification | Acceptance Testing | does the app meet the students' / university's needs? |
| System Design | System Testing | does the complete system work as specified? |
| Software / Component Design | Integration Testing | do the components and interfaces work together? |
| Implementation | Unit Testing | does each single module work correctly? |

### Meaning of the connection

Every development phase gets a corresponding test activity. The tests are planned at the same time as the phase on the left, for example acceptance tests while writing the requirements. The right side then checks the result of the matching phase on the left. This way testing is integrated into every phase instead of being an afterthought, which fixes the Waterfall problem of testing late and in isolation.
